int ra;

main(){
    int r;
    r = setjmp(r);
    if(r == 0){
        fun1();
        return(0);
    }
    else{
        print_str("error\n");
        return(2);
    }
}

setjmp(int v){
    int *pv;
    pv = &v;
    ra = *(pv-1);
    dummy();
    return(0);
}

longjmp(int v){
    int *pv;
    pv = &v;
    *(pv-1) = ra;
    dummy();
    return(1);
}

fun1(){
    print_str("start fun1\n");
    fun2();
    return(0);
}

fun2(){
    int d;
    print_str("start fun2\n");
    longjmp(d);
    return(0);
}

__main(){
    return(0);
}

dummy(int v){
    return(0);
}

print_str(char *str){
    int code;
    code = 4;
    asm(
        "add $a0,%1,$zero\n\t"
        "add $v0,%0,$zero\n\t"
        "syscall"
        :
        : "r" (code), "r" (str));
    return(0);
}
