#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class Recursion{
private:
    static const int MAX=100;
    int v[MAX];
    int tamano;

    int m[MAX][MAX];
    int filas;
    int columnas;
public:
    Recursion(){
        tamano=0;
        filas=0;
        columnas=0;
    }
    void cargarVector(int num){
        if(tamano<MAX){
            v[tamano]=num;
            tamano++;
        }
    }
    void mostrarVector(){
        cout<<"Vector: [";
        for(int i=0;i<tamano;i++){
            if(i==tamano-1){
                cout<<v[i]<<"]";
            }
            else cout<<v[i]<<",";
        }
        cout<< endl;
    }
    void cargarMatriz(int f, int c){
        filas = f;
        columnas = c;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << "Posicion [" << i << "][" << j << "] : ";
                cin >> m[i][j];
            }
        }
    }
    void mostrarMatriz() {
        cout << endl;
        cout << "m=" << endl << endl;
        for (int f = 0; f < filas; f++) {
            cout << "| ";
            for (int c = 0; c < columnas; c++) {
                cout << m[f][c] << "\t";
            }
            cout << "|" << endl;
        }
        cout << endl;
    }
    void vaciarVector(){
        tamano=0;
    }
    void cargarVector(int num){
        if(tamano<MAX){
            v[tamano]=num;
            tamano++;
        }
    }
    void llenarVector(const int datos[], int n, int i){
        if(i==0) tamano=0;
        if(i==n) return;
        cargarVector(datos[i]);
        llenarVector(datos, n, i+1);
    }
    int getTamano(){
        return tamano;
    }
    int getElem(int i){
        return v[i];
    }

    void cargarVectorTeclado(int n, int i){
        if(i==0) tamano=n;
        if(i==tamano) return;
        cout<<"Elemento "<<i+1<<": ";
        cin>>v[i];
        cargarVectorTeclado(n, i+1);
    }

    void mostrarVector(int i){
        if(i==0) cout<<"[";
        if(i==tamano){
            cout<<"]"<<endl;
            return;
        }
        cout<<v[i];
        if(i<tamano-1) cout<<", ";
        mostrarVector(i+1);
    }

    void mostrarSeguido(int i){
        if(i==tamano){
            cout<<endl;
            return;
        }
        cout<<v[i]<<" ";
        mostrarSeguido(i+1);
    }

    void mostrarInverso(int i){
        if(i<0){
            cout<<endl;
            return;
        }
        cout<<v[i]<<" ";
        mostrarInverso(i-1);
    }

    int suma(int i){
        if(i==tamano) return 0;
        return v[i]+suma(i+1);
    }

    int contarPares(int i){
        if(i==tamano) return 0;
        if(v[i]%2==0) return 1+contarPares(i+1);
        return contarPares(i+1);
    }

    void contarSignos(int i, int &pos, int &neg, int &ceros){
        if(i==tamano) return;
        if(v[i]>0) pos++;
        else if(v[i]<0) neg++;
        else ceros++;
        contarSignos(i+1, pos, neg, ceros);
    }

    double promedio(){
        return (double)suma(0)/tamano;
    }

    int contarMultiplos(int i, int k){
        if(i==tamano) return 0;
        if(v[i]%k==0) return 1+contarMultiplos(i+1, k);
        return contarMultiplos(i+1, k);
    }

    int mayor(int i){
        if(i==tamano-1) return v[i];
        int may=mayor(i+1);
        if(v[i]>may) return v[i];
        return may;
    }

    int posMenor(int i){
        if(i==tamano-1) return i;
        int p=posMenor(i+1);
        if(v[i]<=v[p]) return i;
        return p;
    }

    int buscar(int x, int i){
        if(i==tamano) return -1;
        if(v[i]==x) return i;
        return buscar(x, i+1);
    }

    int contar(int x, int i){
        if(i==tamano) return 0;
        if(v[i]==x) return 1+contar(x, i+1);
        return contar(x, i+1);
    }

    void reemplazar(int x, int y, int i){
        if(i==tamano) return;
        if(v[i]==x) v[i]=y;
        reemplazar(x, y, i+1);
    }

    void intercambiar(int a, int b){
        int aux=v[a];
        v[a]=v[b];
        v[b]=aux;
    }

    void invertir(int ini, int fin){
        if(ini>=fin) return;
        intercambiar(ini, fin);
        invertir(ini+1, fin-1);
    }

    bool estaOrdenado(int i){
        if(i>=tamano-1) return true;
        if(v[i]>v[i+1]) return false;
        return estaOrdenado(i+1);
    }

    void sumaParesImpares(int i, int &par, int &impar){
        if(i==tamano) return;
        if(i%2==0) par+=v[i];
        else impar+=v[i];
        sumaParesImpares(i+1, par, impar);
    }

    void eliminarPos(int p){
        if(p>=tamano-1){
            tamano--;
            return;
        }
        v[p]=v[p+1];
        eliminarPos(p+1);
    }

    void ordenarSeleccion(int i){
        if(i>=tamano-1) return;
        int p=posMenor(i);
        if(p!=i) intercambiar(i, p);
        ordenarSeleccion(i+1);
    }

    int busquedaBinaria(int x, int ini, int fin){
        if(ini>fin) return -1;
        int medio=(ini+fin)/2;
        if(v[medio]==x) return medio;
        if(x<v[medio]) return busquedaBinaria(x, ini, medio-1);
        return busquedaBinaria(x, medio+1, fin);
    }

    void borrarIguales(int x, int j){
        if(j>=tamano) return;
        if(v[j]==x){
            eliminarPos(j);
            borrarIguales(x, j);
        }
        else borrarIguales(x, j+1);
    }

    void eliminarDuplicados(int i){
        if(i>=tamano-1) return;
        borrarIguales(v[i], i+1);
        eliminarDuplicados(i+1);
    }

    void separarParesImpares(int izq, int der){
        if(izq>=der) return;
        if(v[izq]%2==0) separarParesImpares(izq+1, der);
        else if(v[der]%2!=0) separarParesImpares(izq, der-1);
        else{
            intercambiar(izq, der);
            separarParesImpares(izq+1, der-1);
        }
    }

    void correrDerecha(int i, int ultimo){
        if(i==0){
            v[0]=ultimo;
            return;
        }
        v[i]=v[i-1];
        correrDerecha(i-1, ultimo);
    }

    void rotar(int k){
        if(tamano<=1) return;
        k=k%tamano;
        if(k==0) return;
        correrDerecha(tamano-1, v[tamano-1]);
        rotar(k-1);
    }

    void mostrarRango(int a, int b){
        if(a>b) return;
        cout<<v[a];
        if(a<b) cout<<", ";
        mostrarRango(a+1, b);
    }

    void subCreciente(int i, int actual, int ini, int &mejor, int &mejorIni){
        if(i==tamano) return;
        if(v[i]>v[i-1]) actual++;
        else{
            actual=1;
            ini=i;
        }
        if(actual>mejor){
            mejor=actual;
            mejorIni=ini;
        }
        subCreciente(i+1, actual, ini, mejor, mejorIni);
    }

    int segundoMayor(int i, int may, bool &existe){
        if(i==tamano){
            existe=false;
            return 0;
        }
        bool hayResto;
        int resto=segundoMayor(i+1, may, hayResto);
        if(v[i]<may && (!hayResto || v[i]>resto)){
            existe=true;
            return v[i];
        }
        existe=hayResto;
        return resto;
    }

    void maxSegmento(int i, int actual, int iniActual, int &mejor, int &ini, int &fin){
        if(i==tamano) return;
        if(v[i]>actual+v[i]){
            actual=v[i];
            iniActual=i;
        }
        else actual+=v[i];
        if(actual>mejor){
            mejor=actual;
            ini=iniActual;
            fin=i;
        }
        maxSegmento(i+1, actual, iniActual, mejor, ini, fin);
    }

    void tamanoMatriz(int f, int c){
        filas=f;
        columnas=c;
    }
    void llenarMatriz(int f, int c, const int datos[], int k){
        if(k==0) tamanoMatriz(f, c);
        if(k==f*c) return;
        m[k/c][k%c]=datos[k];
        llenarMatriz(f, c, datos, k+1);
    }
    int getElemM(int i, int j){
        return m[i][j];
    }

    void cargarMatriz(int i, int j){
        if(i==filas) return;
        if(j==columnas){
            cargarMatriz(i+1, 0);
            return;
        }
        cout<<"Posicion ["<<i<<"]["<<j<<"] : ";
        cin>>m[i][j];
        cargarMatriz(i, j+1);
    }

    void mostrarMatriz(int i, int j){
        if(i==filas) return;
        if(j==0) cout<<"| ";
        if(j==columnas){
            cout<<"|"<<endl;
            mostrarMatriz(i+1, 0);
            return;
        }
        cout<<m[i][j]<<"\t";
        mostrarMatriz(i, j+1);
    }

    int sumaMatriz(int i, int j){
        if(i==filas) return 0;
        if(j==columnas) return sumaMatriz(i+1, 0);
        return m[i][j]+sumaMatriz(i, j+1);
    }

    void paresImparesM(int i, int j, int &pares, int &impares){
        if(i==filas) return;
        if(j==columnas){
            paresImparesM(i+1, 0, pares, impares);
            return;
        }
        if(m[i][j]%2==0) pares++;
        else impares++;
        paresImparesM(i, j+1, pares, impares);
    }

    int mayorM(int i, int j){
        if(j==columnas) return mayorM(i+1, 0);
        if(i==filas-1 && j==columnas-1) return m[i][j];
        int may=mayorM(i, j+1);
        if(m[i][j]>may) return m[i][j];
        return may;
    }

    void menorM(int i, int j, int &men, int &fil, int &col){
        if(i==filas) return;
        if(j==columnas){
            menorM(i+1, 0, men, fil, col);
            return;
        }
        if(m[i][j]<men){
            men=m[i][j];
            fil=i;
            col=j;
        }
        menorM(i, j+1, men, fil, col);
    }

    void signosM(int i, int j, int &pos, int &neg, int &ceros){
        if(i==filas) return;
        if(j==columnas){
            signosM(i+1, 0, pos, neg, ceros);
            return;
        }
        if(m[i][j]>0) pos++;
        else if(m[i][j]<0) neg++;
        else ceros++;
        signosM(i, j+1, pos, neg, ceros);
    }

    bool buscarM(int x, int i, int j, int &fil, int &col){
        if(i==filas){
            fil=-1;
            col=-1;
            return false;
        }
        if(j==columnas) return buscarM(x, i+1, 0, fil, col);
        if(m[i][j]==x){
            fil=i;
            col=j;
            return true;
        }
        return buscarM(x, i, j+1, fil, col);
    }

    int sumaFila(int f, int j){
        if(j==columnas) return 0;
        return m[f][j]+sumaFila(f, j+1);
    }
    void sumarFilas(int i){
        if(i==filas) return;
        cout<<"Fila "<<i<<": "<<sumaFila(i, 0)<<endl;
        sumarFilas(i+1);
    }

    int sumaColumna(int i, int c){
        if(i==filas) return 0;
        return m[i][c]+sumaColumna(i+1, c);
    }
    void sumarColumnas(int j){
        if(j==columnas) return;
        cout<<"Columna "<<j<<": "<<sumaColumna(0, j)<<endl;
        sumarColumnas(j+1);
    }

    int diagonalPrincipal(int i){
        if(i==filas) return 0;
        return m[i][i]+diagonalPrincipal(i+1);
    }

    int diagonalSecundaria(int i){
        if(i==filas) return 0;
        return m[i][filas-1-i]+diagonalSecundaria(i+1);
    }

    void encimaDebajo(int i, int j, int &encima, int &debajo){
        if(i==filas) return;
        if(j==columnas){
            encimaDebajo(i+1, 0, encima, debajo);
            return;
        }
        if(j>i) encima+=m[i][j];
        else if(i>j) debajo+=m[i][j];
        encimaDebajo(i, j+1, encima, debajo);
    }

    bool esBorde(int i, int j){
        return i==0 || i==filas-1 || j==0 || j==columnas-1;
    }

    void mostrarBorde(int i, int j){
        if(i==filas){
            cout<<endl;
            return;
        }
        if(j==columnas){
            mostrarBorde(i+1, 0);
            return;
        }
        if(esBorde(i, j)) cout<<m[i][j]<<" ";
        mostrarBorde(i, j+1);
    }

    int sumaBorde(int i, int j){
        if(i==filas) return 0;
        if(j==columnas) return sumaBorde(i+1, 0);
        if(esBorde(i, j)) return m[i][j]+sumaBorde(i, j+1);
        return sumaBorde(i, j+1);
    }

    void mostrarTranspuesta(int j, int i){
        if(j==columnas) return;
        if(i==filas){
            cout<<endl;
            mostrarTranspuesta(j+1, 0);
            return;
        }
        cout<<m[i][j]<<"\t";
        mostrarTranspuesta(j, i+1);
    }

    int mayorFila(int f, int j){
        if(j==columnas-1) return m[f][j];
        int may=mayorFila(f, j+1);
        if(m[f][j]>may) return m[f][j];
        return may;
    }
    void mayorCadaFila(int i){
        if(i==filas) return;
        cout<<"Fila "<<i<<": "<<mayorFila(i, 0)<<endl;
        mayorCadaFila(i+1);
    }

    bool esSimetrica(int i, int j){
        if(filas!=columnas) return false;
        if(i==filas) return true;
        if(j==columnas) return esSimetrica(i+1, 0);
        if(m[i][j]!=m[j][i]) return false;
        return esSimetrica(i, j+1);
    }

    void mostrarRotada(int j, int i){
        if(j==columnas) return;
        if(i<0){
            cout<<endl;
            mostrarRotada(j+1, filas-1);
            return;
        }
        cout<<m[i][j]<<endl;
        mostrarRotada(j, i-1);
    }

    void ladoArriba(int f, int c, int cFin){
        if(c>cFin) return;
        cout<<m[f][c]<<" ";
        ladoArriba(f, c+1, cFin);
    }
    void ladoDerecho(int c, int f, int fFin){
        if(f>fFin) return;
        cout<<m[f][c]<<" ";
        ladoDerecho(c, f+1, fFin);
    }
    void ladoAbajo(int f, int c, int cIni){
        if(c<cIni) return;
        cout<<m[f][c]<<" ";
        ladoAbajo(f, c-1, cIni);
    }
    void ladoIzquierdo(int c, int f, int fIni){
        if(f<fIni) return;
        cout<<m[f][c]<<" ";
        ladoIzquierdo(c, f-1, fIni);
    }
    void espiral(int fIni, int fFin, int cIni, int cFin){
        if(fIni>fFin || cIni>cFin){
            cout<<endl;
            return;
        }
        ladoArriba(fIni, cIni, cFin);
        ladoDerecho(cFin, fIni+1, fFin);
        if(fIni<fFin) ladoAbajo(fFin, cFin-1, cIni);
        if(cIni<cFin) ladoIzquierdo(cIni, fFin-1, fIni+1);
        espiral(fIni+1, fFin-1, cIni+1, cFin-1);
    }

    bool esTriangularSuperior(int i, int j){
        if(filas!=columnas) return false;
        if(i==filas) return true;
        if(j==columnas) return esTriangularSuperior(i+1, 0);
        if(i>j && m[i][j]!=0) return false;
        return esTriangularSuperior(i, j+1);
    }

    void regionesTriangulares(int i, int j, int &sup, int &inf){
        if(i==filas) return;
        if(j==columnas){
            regionesTriangulares(i+1, 0, sup, inf);
            return;
        }
        if(i<=j) sup+=m[i][j];
        if(i>=j) inf+=m[i][j];
        regionesTriangulares(i, j+1, sup, inf);
    }

    int menorFila(int f, int j){
        if(j==columnas-1) return m[f][j];
        int men=menorFila(f, j+1);
        if(m[f][j]<men) return m[f][j];
        return men;
    }
    int mayorColumna(int i, int c){
        if(i==filas-1) return m[i][c];
        int may=mayorColumna(i+1, c);
        if(m[i][c]>may) return m[i][c];
        return may;
    }
    bool puntoSilla(int i, int j){
        if(i==filas) return false;
        if(j==columnas) return puntoSilla(i+1, 0);
        bool encontrado=false;
        if(m[i][j]==menorFila(i, 0) && m[i][j]==mayorColumna(0, j)){
            cout<<"Punto de silla: valor "<<m[i][j]<<"; fila "<<i<<"; columna "<<j<<endl;
            encontrado=true;
        }
        bool otros=puntoSilla(i, j+1);
        return encontrado || otros;
    }

    int contarSeguidos(int i, int j, int di, int dj, int val){
        if(i<0 || i>=filas || j<0 || j>=columnas || m[i][j]!=val) return 0;
        return 1+contarSeguidos(i+di, j+dj, di, dj, val);
    }
    void repetir(int val, int k){
        if(k==0) return;
        cout<<val;
        if(k>1) cout<<", ";
        repetir(val, k-1);
    }
    bool secuencia(int i, int j, int k){
        if(i==filas) return false;
        if(j==columnas) return secuencia(i+1, 0, k);
        int val=m[i][j];
        string dir="";
        if(contarSeguidos(i, j, 0, 1, val)>=k) dir="horizontal";
        else if(contarSeguidos(i, j, 1, 0, val)>=k) dir="vertical";
        else if(contarSeguidos(i, j, 1, 1, val)>=k) dir="diagonal principal";
        else if(contarSeguidos(i, j, 1, -1, val)>=k) dir="diagonal secundaria";
        if(dir!=""){
            cout<<"Si existe: "<<dir<<" [";
            repetir(val, k);
            cout<<"]"<<endl;
            return true;
        }
        return secuencia(i, j+1, k);
    }

    int caminoMaximo(int i, int j){
        if(i==filas-1 && j==columnas-1) return m[i][j];
        if(i==filas-1) return m[i][j]+caminoMaximo(i, j+1);
        if(j==columnas-1) return m[i][j]+caminoMaximo(i+1, j);
        int der=caminoMaximo(i, j+1);
        int aba=caminoMaximo(i+1, j);
        if(der>aba) return m[i][j]+der;
        return m[i][j]+aba;
    }
    void mostrarCamino(int i, int j){
        cout<<m[i][j];
        if(i==filas-1 && j==columnas-1){
            cout<<endl;
            return;
        }
        cout<<" -> ";
        if(i==filas-1) mostrarCamino(i, j+1);
        else if(j==columnas-1) mostrarCamino(i+1, j);
        else if(caminoMaximo(i, j+1)>caminoMaximo(i+1, j)) mostrarCamino(i, j+1);
        else mostrarCamino(i+1, j);
    }
};
int main(){
    Recursion v1;
    v1.cargarVector(3);
    v1.cargarVector(4);
    v1.mostrarVector();

    Recursion m1;
    m1.cargarMatriz(2,2);
    m1.mostrarMatriz();
    return 0;
}