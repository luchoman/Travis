#include "Proxy.hpp"

Proxy::Proxy(){}
Proxy::~Proxy(){}

string Proxy::get_ProxyUrl(int posicion){
	
	int size_proxyUrl = this->proxyUrl.size();
	if ((posicion>=0)&&(posicion<size_proxyUrl)){
		return this->proxyUrl[posicion];
		}
		return "-1";
	};
	
int Proxy::get_TotalProxiesAlmacenados(void){return this->proxyUrl.size();};
void Proxy::set_ProxyUrl(string url){
	
		this->proxyUrl.push_back(url);
	
	};

void Proxy::set_ProxyUrlDesdeArchivo(string url){
	
	
	ifstream input(url.c_str());
		
		while(!input.eof()) 
		{
			char cadena[128];
			input.getline(cadena, 128);
			string tmp = cadena;
			
				this->proxyUrl.push_back(cadena);
				cout<<cadena<<endl;
			
		
			};
	
	
	};
	
int Proxy::ping(string target)
{
	target = Proxy::retornar_url_sin_puerto(target);
	string comando = "ping -c 1 " + target;
	cout << comando<<endl;
	int retorno = system(comando.c_str());
	system("clear");
	if (retorno == 0)
	{
		return 0;
		}

return -1;
}
string Proxy::retornar_url_sin_puerto(string target)
{
	int size=target.size();
	string target2="";
	for(int i=0; i<size;i++)
	{
		if(target.at(i)!=':')
		{
			target2=target2+target.at(i);
		}
		else{
			i=target.size();
		}
	}
	return target2;
}
