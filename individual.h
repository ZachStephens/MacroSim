#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H


class Individual
{
private:
    float wellbeing;
    float networth;
    float humancapital;

    
public:
    Individual();
    void Update();
    void transact();
    void produce();
    void consume();
};

#endif // INDIVIDUAL_H
