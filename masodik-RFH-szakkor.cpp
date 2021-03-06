#include <AgentHost.h>
#include <ClientPool.h>
using namespace malmo;


#include <cstdlib>
#include <exception>
#include <iostream>
using namespace std;

int main(int argc, const char **argv)
{
    AgentHost agent_host;

    try
    {
        agent_host.parseArgs(argc, argv);
    }
    catch( const exception& e )
    {
        cout << "ERROR: " << e.what() << endl;
        cout << agent_host.getUsage() << endl;
        return EXIT_SUCCESS;
    }
    if( agent_host.receivedArgument("help") )
    {
        cout << agent_host.getUsage() << endl;
        return EXIT_SUCCESS;
    }

    std::ifstream xmlf{"nb4tf4i_d.xml"};
    std::string  xml{std::istreambuf_iterator<char>(xmlf),std::istreambuf_iterator<char>()};



    MissionSpec my_mission(xml,true);


    MissionRecordSpec my_mission_record("./saved_data.tgz");


    int attempts = 0;
    bool connected = false;
    do {
        try {
            agent_host.startMission(my_mission, my_mission_record);
            connected = true;
        }
        catch (exception& e) {
            cout << "Error starting mission: " << e.what() << endl;
            attempts += 1;
            if (attempts >= 3)
                return EXIT_FAILURE;
            else
                boost::this_thread::sleep(boost::posix_time::milliseconds(1000));   .
        }
    } while (!connected);

    WorldState world_state;

    cout << "Waiting for the mission to start" << flush;
    do {
        cout << "." << flush;
        boost::this_thread::sleep(boost::posix_time::milliseconds(100));
        world_state = agent_host.getWorldState();
        for( boost::shared_ptr<TimestampedString> error : world_state.errors )
            cout << "Error: " << error->text << endl;
    } while (!world_state.has_mission_begun);
    cout << endl;


    do {
        agent_host.sendCommand("move 1");
        boost::this_thread::sleep(boost::posix_time::milliseconds(500));

	agent_host.sendCommand("move 1");
        boost::this_thread::sleep(boost::posix_time::milliseconds(500));

	agent_host.sendCommand("move 1");
        boost::this_thread::sleep(boost::posix_time::milliseconds(500));

	agent_host.sendCommand("turn 1");
        boost::this_thread::sleep(boost::posix_time::milliseconds(500));

        world_state = agent_host.getWorldState();

        for( boost::shared_ptr<TimestampedString> error : world_state.errors )
            cout << "Error: " << error->text << endl;
    } while (world_state.is_mission_running);

    cout << "Mission has stopped." << endl;

    return EXIT_SUCCESS;
}
