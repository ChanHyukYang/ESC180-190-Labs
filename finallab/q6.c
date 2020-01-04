struct var {
    float constant;
    float exponent;
    struct var *next;
}; typedef struct var var;
struct poly {
    var *a;
    var *b;
    var *c;
    var *d;
};

