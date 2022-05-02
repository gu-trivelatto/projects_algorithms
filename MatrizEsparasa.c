void AtribuiEsparsa (MatrizEsparsa a, int i, int j, float x){
    RegEsparsa *p, *q, *pp, *qq, *r;
    int k;

    p = a;
    q = a;

    for(k = 0; k <= i; k++)
        p = p->abaixo;

    for(k = 0; k <= j; k++)
        q = q->direita;

    do{
        pp = p;
        p = p->direita;
    }while(p->coluna < j);

    do{
        qq = q;
        q = q->abaixo;
    }while(q->linha < i);

    if(p->coluna == j){
        if(x != 0.0) p->valor = x;
        else{  /*Remove elemento*/
            qq->abaixo = p->abaixo;
            pp->direita = p->direita;
            free(p)
        }
    }
    /*Insere elemento*/
    else if(x != 0.0){
        r = AlocaRegEsparsa();
        r->coluna = j;
        r->linha = i;
        r->valor = x;
        r->abaixo = qq->abaixo;
        r->direita = pp->direita;
        qq->abaixo = r;
        pp->direita = r;
    }
}
