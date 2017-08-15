semaphore mutex1=1;
semaphore mutex2=1;
semaphore empty=n;
semaphore full=0;
producer(){
    while (1){
        生产一个产品;
        P(empty);
        P(mutex2);
        把产品放入缓冲区;
        V(mutex2);
        V(full);
    }
}
consumer(){
    while (1){
        P(mutex1);  //连续取10次
        for(int i=0;i<10;i++){
            P(full);
            P(mutex2);
            从缓冲区取出一件产品;
            V(mutex2);
            V(empty);
            消费这件产品;
        }
        V(mutex1);
    }
}