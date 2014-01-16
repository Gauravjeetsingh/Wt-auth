#include <Wt/WServer>

#include "custom_auth.h"
#include "session.h"

CustomAuth::CustomAuth(const WEnvironment &env)
	   :WApplication(env)
{
new WText("Hello World", root());
new AuthForm(root());
}

WApplication *createApplication(const WEnvironment &env)
{
    return new CustomAuth(env);
}


int main(int argc, char **argv)
{
   try{
                Wt::WServer server(argv[0]);

                server.setServerConfiguration(argc,argv, WTHTTP_CONFIGURATION);
                server.addEntryPoint(Wt::Application, createApplication);
		session::configureAuth();

                if(server.start()){
                        Wt::WServer::waitForShutdown();
                        server.stop();
                }
        } catch (Wt::WServer::Exception& e) {
                std::cerr << e.what() << std::endl;
        } catch (std::exception &e) {
                std::cerr<< "exception" << e.what() <<std::endl;
        }
 }
               
