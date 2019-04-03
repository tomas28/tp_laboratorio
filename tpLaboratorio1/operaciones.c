double sumar(double x,double y)
{
    double result;
    result= x+y;
    return result;
}
double restar(double x,double y)
{
    double result;
    result= x-y;
    return result;
}
double multiplicar(double x,double y)
{
    double result;
    result= x*y;
    return result;
}
double dividir(double x,double y)
{
    double result;
    if(y==0)
    {
        return 0;
    }
    else
    {
        result= x/y;
        return result;
    }
}
int factorial(double x)
{
    int resp;
    if(x<0){
        return 0;
    }else{
        if(x==1){
            return 1;
        }
        resp=(int)x* factorial(x-1);
        return (resp);
    }



}

