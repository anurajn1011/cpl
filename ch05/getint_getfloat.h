#ifndef FUNCTIONS
#define FUNCTIONS

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