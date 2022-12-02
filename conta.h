typedef struct Conta * p_conta;

//inicializar a conta
void inicializar(p_conta pConta[], int tamanho);

void inserir(p_conta pConta[], int posicao);

void listar(p_conta pConta[], int tamanho);

void depositar(p_conta pConta[], int tamanho);

void sacar(p_conta pConta[], int tamanho);
