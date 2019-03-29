#ifdef module1_EXPORTS // this gets automatically defined by CMake when building the DLL
#define MODULE1_EXPORT __declspec(dllexport)
#else
#define MODULE1_EXPORT __declspec(dllimport)
#endif

namespace module1{

    MODULE1_EXPORT void test(int val1);

}
