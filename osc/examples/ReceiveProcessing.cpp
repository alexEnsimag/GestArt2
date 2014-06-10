/* 
    Example of two different ways to process received OSC messages using oscpack.
    Receives the messages from the SimpleSend.cpp example.
*/

#include <iostream>
#include <cstring>

#if defined(__BORLANDC__) // workaround for BCB4 release build intrinsics bug
namespace std {
using ::__strcmp__;  // avoid error: E2316 '__strcmp__' is not a member of 'std'.
}
#endif

#include "osc/OscReceivedElements.h"
#include "osc/OscPacketListener.h"
#include "ip/UdpSocket.h"


#define PORT 12345

class ExamplePacketListener : public osc::OscPacketListener {
protected:

    virtual void ProcessMessage( const osc::ReceivedMessage& m, 
				const IpEndpointName& remoteEndpoint )
    {
        (void) remoteEndpoint; // suppress unused parameter warning

        try{
            // osc::OsckPacketListener handles the bundle traversal.
			osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();
			float x = (arg++)->AsFloat();
			float y = (arg++)->AsFloat();
			float z = (arg++)->AsFloat();
			
		    if(std::strcmp( m.AddressPattern(), "/head_pos_body" ) == 0) {
				; // écrire dans les 2 fichiers
		    } else if(std::strcmp( m.AddressPattern(), "/leftshoulder_pos_body" ) == 0) {
				;
		    } else if(std::strcmp( m.AddressPattern(), "/leftelbow_pos_body" ) == 0) {
				;
		    } else if(std::strcmp( m.AddressPattern(), "/rightshoulder_pos_body" ) == 0) {
				;
		    } else if(std::strcmp( m.AddressPattern(), "/rightelbow_pos_body" ) == 0) {
				;
		    } else if(std::strcmp( m.AddressPattern(), "/torso_pos_body" ) == 0) {
				;
		    } else if(std::strcmp( m.AddressPattern(), "/lefthip_pos_body" ) == 0) {
				;
		    } else if(std::strcmp( m.AddressPattern(), "/leftknee_pos_body" ) == 0) {
				;
		    } else if(std::strcmp( m.AddressPattern(), "/righthip_pos_body" ) == 0) {
				;
		    } else if(std::strcmp( m.AddressPattern(), "/rightknee_pos_body" ) == 0) {
				;
		    } else if(std::strcmp( m.AddressPattern(), "/lefthand_pos_body" ) == 0) {
				;
		    } else if(std::strcmp( m.AddressPattern(), "/righthand_pos_body" ) == 0) {
				;
		    } else {
				std::cout << "Error message " << m.AddressPattern() << "\n";
		    	return;
		    }
			std::cout << m.AddressPattern() << " " << x << " " << y << " " << z << "\n";

        }catch( osc::Exception& e ){
            // any parsing errors such as unexpected argument types, or 
            // missing arguments get thrown as exceptions.
            std::cout << "error while parsing message: "
                << m.AddressPattern() << ": " << e.what() << "\n";
        }
    }
};

int main(int argc, char* argv[])
{
    (void) argc; // suppress unused parameter warnings
    (void) argv; // suppress unused parameter warnings

    ExamplePacketListener listener;
    UdpListeningReceiveSocket s(
            IpEndpointName( IpEndpointName::ANY_ADDRESS, PORT ),
            &listener );

    std::cout << "press ctrl-c to end\n";

    s.RunUntilSigInt();

    return 0;
}

