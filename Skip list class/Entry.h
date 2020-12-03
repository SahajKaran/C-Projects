//Sahaj Karan
//301386551
#include<string>
#include<ctime>
using namespace std;
class EntryException {
	private:	//Private member
		string error;
	public:		//Public members.
		EntryException(const string& e)
		:error(e){};
		string getError() const { return error; }
};
class Entry{
    private:
        int key;
        string data;        
    public:
        Entry(){ random(); } //constructor
        Entry(int key ,string data){
             this -> data = data;
             this -> key = key;
        }
        void random(){         
            key=(rand()%100);//Returns random key 0-99 inclusive
            
            data="";
            char character;
            for(int i=0;i<3;i++){
                character='a'+rand()%26;
                data+=character;//Return 3 random characters in form of a string
            }
        };
        //getters
        int getKey() const {return key;}
        string getData() const {return data;}
        //setters
        void setKey(int key){this->key=key;}
        void setData(string data){this->data=data;}        
       
        string toString() const { return "(" + to_string(key) + "," + data+ ")";}
        ~Entry(){};//destructor
};