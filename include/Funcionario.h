/* 
Class: Funcionario
Author: Arnaldo Barbosa    
*/
#ifndef _FUNCIONARIO_
#define _FUNCIONARIO_
    class A
    {
    public:
    void f (int i);
    void g (int j = 0);
    };
    inline void A::f (int i) { ... }
    bool operator == (A const & a1, A const & a2);
#endif