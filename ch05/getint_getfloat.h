#ifndef FUNCTIONS
#define FUNCTIONS

#ifdef _WIN32
  #ifdef WINDOWS_DLL_EXPORT
    #define DLL_EXPORT __declspec(dllexport)  // export functions
  #else
    #define DLL_EXPORT __declspec(dllimport)  // import functions
  #endif
#else
  #define DLL_EXPORT  // in the event we are using linux
#endif

#ifdef __cplusplus
extern "C" {
#endif 

int getch();
void ungetch();
int power(int base, int pow);
float getfloat(float *pn);

#ifdef __cplusplus
}
#endif

#endif