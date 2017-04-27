#include <stdio.h>
#include <stdlib.h>
/** \brief Suma los numeros ingresados.
 *
 * \param x float Primer numero.
 * \param y float Segundo numero.
 * \return float El resultado de la suma.
 *
 */
float mSum(float x, float y)
{
    float tot;
    tot=x+y;
    return tot;
}
/** \brief Resta el segundo numero al primer numero.
 *
 * \param x float Primer numero.
 * \param y float Segundo numero.
 * \return float El resultado de la resta.
 *
 */
float mRes(float x, float y)
{
    float tot;
    tot=x-y;
    return tot;
}
/** \brief Divide el primer numero por el segundo.
 *
 * \param x float Dividendo.
 * \param y float Divisor.
 * \return float Cociente.
 *
 */
float mDiv(float x, float y)
{
    float tot;
    tot=x/y;
    return tot;
}
/** \brief Multiplica los numeros ingresados.
 *
 * \param x float Primer numero.
 * \param y float Segundo numero.
 * \return float Resultado de la multiplicacion.
 *
 */
float mMul(float x, float y)
{
    float tot;
    tot=x*y;
    return tot;
}
/** \brief Saca el factorial del numero ingresado.
 *
 * \param x float Numero a factorear.
 * \return float Resultado del factoreo.
 *
 */
float mFac(float x)
{
    float tot;
    int fla=1;
    if (fla==1)
    {
        tot=x;
        fla=0;
    }
    while(x>1)
    {
        tot=tot*(x-1);
        x--;
    }
    return tot;
}
