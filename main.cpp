#include <chrono>
#include <Windows.h>

// apis
#include <core.h>
#define CLIENT

int main(int _Argc, char** _Argv) {
	// Initialize ENet
	cat::core::Core_enet_initialize();

#ifdef CLIENT
	// Create Client
	cat::core::Core_enet_client_create(1);
	cat::core::Core_enet_client_connect("localhost", 2330, 1);
#else
	// Create Server
	cat::core::Core_enet_server_create("localhost", 2330, 1, 32);
#endif

	while (true) {
		using namespace std::chrono;
		cat::core::Core_enet_pollevents(1s);

	#ifdef CLIENT
		// Client Sent Packet Data To Server
		constexpr const char* Data = "hello, world\0";
		cat::core::Core_enet_client_send(Data, std::strlen(Data)+1, 0, NULL);
	#endif // CLIENT
	}

	// Deinitialize ENet
	cat::core::Core_enet_deinitialize();
	return 0;
}