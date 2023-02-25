/**
 * JSON language, developed in C++ by
 * csd4411 && csd4448
 * hy352
 * 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <vector>
#include <map>
#include <assert.h>
#include <string.h>

#define ORIAKA_INT_MAX  2147483646
#define PROGRAM_BEGIN ;int main(){ string member = "MEMBERS"; string temp; type TO_KSEKARFOMA; string key = "key"
#define PROGRAM_END ;return 0;}


#define JSON(var) ;type var
#define KEY(name) type(temp = (key + #name)) = 0 ? 0
#define STRING(name) type(temp = name)
#define NUMBER(name) type(name)
#define OBJECT *new type
#define ARRAY type(member)
#define TRUE type(true)
#define FALSE type(false)
#define PRINT ;cout <<
#define ERASE ;TO_KSEKARFOMA *=

#define SIZE_OF(obj) obj.SIZE_OF_MACRO()
#define IS_EMPTY(obj) obj.IS_EMPTY_MACRO()
#define HAS_KEY(obj,KLEIDI) obj.HAS_KEY_MACRO(KLEIDI)
#define TYPE_OF(obj) obj.TYPE_OF_MACRO()


using namespace std;


enum JSON_type { JSON_STRING, JSON_NUMBER, JSON_OBJECT, JSON_ARRAY, JSON_TRUE, JSON_FALSE, JSON_NULL} JSON_type;

struct type{
public:
    

    // CONSTRUCTORS 
    type() { this->jsonType = JSON_NULL; }
    type(initializer_list<type> Head){
        this->head.insert(this->head.begin() , Head);
        this->jsonType = JSON_OBJECT;
    }
    type(string &new_string){ 
        this->key = new_string.substr(0, 3);
        if (this->key != "key"){
            this->key == "";
            this->str = new_string;
        }else{
            this->key = new_string.substr(3,new_string.length() - 3);
        };
        this->jsonType = JSON_STRING; 
    }
    type(const int integer){  this->number = integer; this->jsonType = JSON_NUMBER; }
    type(const double integer) {this->number = integer; this->jsonType = JSON_NUMBER;}
    type(const bool boolean) { this->boolean = boolean; if(boolean){ this->jsonType = JSON_TRUE;} else {this->jsonType = JSON_FALSE;}}

    friend ostream &operator<<(ostream &os, type &js){

        if( js.special_treatment == 1){
            js.special_treatment = 0;

            if(js.temp_head[0].jsonType == JSON_STRING){
                cout << js.temp_head[0].str;
            }else if(js.temp_head[0].jsonType == JSON_NUMBER){
                cout << js.temp_head[0].number;
            }else if(js.temp_head[0].jsonType == JSON_FALSE){
                cout << "FALSE" << endl;
            }else if(js.temp_head[0].jsonType == JSON_TRUE){
                cout << "TRUE" << endl;
            }else if(js.temp_head[0].jsonType == JSON_ARRAY){
                cout << "array[";
                int i;
                for(i = 0; i < js.temp_head[0].array.size() - 1; i++){
                    cout << js.temp_head[0].array[i];
                    cout << ", ";
                }
                cout << js.temp_head[0].array[i];
                cout << "]";
            }else if(js.temp_head[0].jsonType == JSON_OBJECT){
                cout << js.temp_head[0].head.size() << endl;
                for(int i = 0; i < js.temp_head[0].head.size(); i++){
                    if ( js.temp_head[0].head[i].key != ""){
                        cout << js.temp_head[0].head[i].key << ":";
                    }
                    cout << js.temp_head[0].head[i];
                }
            }
        }else{
            if(js.jsonType == JSON_STRING){
                cout << js.str << endl;
            }else if(js.jsonType == JSON_NUMBER){
                cout << js.number << endl;
            }else if(js.jsonType == JSON_FALSE){
                cout << js.str << "FALSE" << endl;
            }else if(js.jsonType == JSON_TRUE){
                cout << js.str << "TRUE" << endl;
            }else if(js.jsonType == JSON_ARRAY){
                if (js.head.size() == 1){
                    if ( js.head[0].number != ORIAKA_INT_MAX){
                        cout << js.head[0];
                    }
                }
                else{
                    cout << "array[";
                    int i;
                    for(i = 0; i < js.array.size() - 1; i++){
                        cout << js.array[i] ;
                        cout << ", ";
                    }
                    cout << js.array[i];

                    cout << "]" << endl;
                }

            }else if(js.jsonType == JSON_OBJECT){
                for(int i = 0; i < js.head.size(); i++){
                    if ( js.head[i].key != ""){
                        cout << js.head[i].key << ":";
                    }
                    cout << js.head[i];
                }
            }
        }
        return os;
    }
    friend ostream &operator<<(ostream &os, type *js){

        if( js->special_treatment == 1){
            js->special_treatment = 0;

            if(js->temp_head[0].jsonType == JSON_STRING){
                cout << js->temp_head[0].str;
            }else if(js->temp_head[0].jsonType == JSON_NUMBER){
                cout << js->temp_head[0].number;
            }else if(js->temp_head[0].jsonType == JSON_FALSE){
                cout << "FALSE" << endl;
            }else if(js->temp_head[0].jsonType == JSON_TRUE){
                cout << "TRUE" << endl;
            }else if(js->temp_head[0].jsonType == JSON_ARRAY){
                cout << "array[";
                int i;
                for(i = 0; i < js->temp_head[0].array.size() - 1; i++){
                    cout << js->temp_head[0].array[i];
                    cout << ", ";
                }
                cout << js->temp_head[0].array[i];
                cout << "]";
            }else if(js->temp_head[0].jsonType == JSON_OBJECT){
                cout << js->temp_head[0].head.size() << endl;
                for(int i = 0; i < js->temp_head[0].head.size(); i++){
                    if ( js->temp_head[0].head[i].key != ""){
                        cout << js->temp_head[0].head[i].key << ":";
                    }
                    cout << js->temp_head[0].head[i];
                }
            }
        }else{
            if(js->jsonType == JSON_STRING){
                cout << js->str << endl;
            }else if(js->jsonType == JSON_NUMBER){
                cout << js->number << endl;
            }else if(js->jsonType == JSON_FALSE){
                cout << js->str << "FALSE" << endl;
            }else if(js->jsonType == JSON_TRUE){
                cout << js->str << "TRUE" << endl;
            }else if(js->jsonType == JSON_ARRAY){
                if (js->head.size() == 1){
                    if ( js->head[0].number != ORIAKA_INT_MAX){
                        cout << js->head[0];
                    }
                }
                else{
                    cout << "array[";
                    int i;
                    for(i = 0; i < js->array.size() - 1; i++){
                        cout << js->array[i] ;
                        cout << ", ";
                    }
                    cout << js->array[i];

                    cout << "]" << endl;
                }

            }else if(js->jsonType == JSON_OBJECT){
                for(int i = 0; i < js->head.size(); i++){
                    if ( js->head[i].key != ""){
                        cout << js->head[i].key << ":";
                    }
                    cout << js->head[i];
                }
            }
        }
        return os;
    }

    type &operator=(type value){

        this->jsonType = value.jsonType;

        if(this->number != ORIAKA_INT_MAX && value.number != ORIAKA_INT_MAX){
            this->array.push_back(this->number);
            this->array.push_back(value.number);
        }
        if(value.jsonType == JSON_STRING){
            this->str = value.str;
        }else if(value.jsonType == JSON_NUMBER){
            this->number = value.number;
        }else if(value.jsonType == JSON_TRUE || value.jsonType == JSON_FALSE){
            this->boolean = value.boolean;
        }else if(value.jsonType == JSON_OBJECT){
            this->head.push_back(value);
        }else{
            for(int i = 0; i < value.array.size(); i++){
                this->array.push_back(value.array[i]);
            }
        }
        return *this;
    };
    type &operator=(type *value){

        this->jsonType = value->jsonType;

        if(value->jsonType == JSON_STRING){
            this->str = value->str;
        }else if(value->jsonType == JSON_NUMBER){
            this->number = value->number;
        }else if(value->jsonType == JSON_TRUE || value->jsonType == JSON_FALSE){
            this->boolean = value->boolean;
        }else if(value->jsonType == JSON_OBJECT){
            this->head.push_back(value);
        }else{
            for(int i = 0; i < value->array.size(); i++){
                this->array.push_back(value->array[i]);
            }
        }
        return *this;
    };
    type &operator,(type value){

        if(value.jsonType == JSON_NUMBER){

            if(this->isArrayEmpty()){
                this->array.push_back(this->number);
            }

            this->array.push_back(value.number);
            this->jsonType = JSON_ARRAY;

        }else{

            this->reset();
            this->jsonType = JSON_OBJECT;

            this->head.push_back(*this);
            this->head.push_back(value);
        }

        return *this;
    };
    type &operator,(type *value){

        if(value->jsonType == JSON_NUMBER){

            if(this->isArrayEmpty()){
                this->array.push_back(this->number);
            }

            this->array.push_back(value->number);
            this->jsonType = JSON_ARRAY;

        }else{

            this->reset();
            this->jsonType = JSON_OBJECT;

            this->head.push_back(*this);
            this->head.push_back(value);
        }

        return *this;
    };
    type operator[](type Head){return Head;};
    type operator[](type *Head){return Head;};
    type &operator[](int pos){
        
        this->head.clear();
        type temp_obj = new type();
        temp_obj.jsonType = JSON_NUMBER;
        temp_obj.number = ORIAKA_INT_MAX;
        if(this->array.size() == 0){
            cout << "Cannot access empty array!" << endl;
        }else if(this->array.size() <= pos){
            cout << "Position in array greater than size!" << endl;
        }else{
            temp_obj.number = this->array[pos];
        }
        this->head.push_back(temp_obj);
        return *this;
    }
    type &operator[](const char* pos){

        this->temp_head.clear();
        type temp_obj = new type();
        for(int i = 0; i < this->head.size(); i++){
            if (this->head[i].key == pos){
                if ( this->head[i].jsonType == JSON_STRING){
                    temp_obj.str = this->head[i].str;
                    temp_obj.jsonType = JSON_STRING;
                }else if ( this->head[i].jsonType == JSON_NUMBER){
                    temp_obj.number = this->head[i].number;
                    temp_obj.jsonType = JSON_NUMBER;
                }else if ( this->head[i].jsonType == JSON_FALSE){
                    temp_obj.boolean = false;
                    temp_obj.jsonType = JSON_FALSE;
                }else if ( this->head[i].jsonType == JSON_TRUE){
                    temp_obj.boolean = true;
                    temp_obj.jsonType = JSON_TRUE;
                }else if ( this->head[i].jsonType == JSON_ARRAY){
                    temp_obj.array = this->head[i].array;
                    temp_obj.jsonType = JSON_ARRAY;
                }else if ( this->head[i].jsonType == JSON_OBJECT){
                    temp_obj.head = this->head[i].head;
                    temp_obj.jsonType = JSON_OBJECT;
                }
                this->special_treatment = 1;
                this->temp_head.push_back(temp_obj);
                return *this;
            }
        }
        cout << "This key: " << pos << " doesnt exist in the object!" << endl;
        return *this;
    }

    //ERASE OPERATOR
    type &operator*=( type &value ){

        if(value.jsonType == JSON_OBJECT || value.jsonType == JSON_ARRAY){
            value.reset();
        }else
            cout<< "Only objects and arrays can be erased!"<< endl;

    return *this;

    }
    type &operator*=( type *value ){

        if(value->jsonType == JSON_OBJECT || value->jsonType == JSON_ARRAY){
            value->reset();
        }else
            cout<< "Only objects and arrays can be erased!"<< endl;

    return *this;

    }


    //ARITHMETIC OPERATORS
    type &operator-(type value){

        if(this->jsonType == JSON_NUMBER && value.jsonType == JSON_NUMBER){
            this->number -= value.number;
        }

        return *this;
    }
    type &operator-(type *value){

        if(this->jsonType == JSON_NUMBER && value->jsonType == JSON_NUMBER){
            this->number -= value->number;
        }

        return *this;
    }
    type &operator*( type value ){
        
       if(this->jsonType == JSON_NUMBER && value.jsonType == JSON_NUMBER ){
            this->number *= value.number;
        }else{
            for(int i = 0; i < this->head.size() ; i++ ){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type(this->head[i].number * value.number);
                    return *temp;
                }
            }
        }

        return *this;
    
    }
    type &operator*( type *value ){
        
       if(this->jsonType == JSON_NUMBER && value->jsonType == JSON_NUMBER ){
            this->number *= value->number;
        }else{
            for(int i = 0; i < this->head.size() ; i++ ){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type(this->head[i].number * value->number);
                    return *temp;
                }
            }
        }

        return *this;
    
    }
    type &operator/(type value){

        if(this->jsonType == JSON_NUMBER && value.jsonType == JSON_NUMBER){
            this->number /= value.number;
        }else{
            for(int i = 0; i < this->head.size(); i++){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type(this->head[i].number / value.number);
                    return *temp;
                }
            }
        }
        return *this;
    }
    type &operator/(type *value){

        if(this->jsonType == JSON_NUMBER && value->jsonType == JSON_NUMBER){
            this->number /= value->number;
        }else{
            for(int i = 0; i < this->head.size(); i++){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type(this->head[i].number / value->number);
                    return *temp;
                }
            }
        }
        return *this;
    }
    type &operator%(type value){

        if(this->jsonType == JSON_NUMBER && value.jsonType == JSON_NUMBER){
            this->number = (int)this->number % (int)value.number;
        }else{
            for(int i = 0; i < this->head.size(); i++){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type((int)this->head[i].number % (int)value.number);
                    return *temp;
                }
            }
        }
        return *this;

    }
    type &operator%(type *value){

        if(this->jsonType == JSON_NUMBER && value->jsonType == JSON_NUMBER){
            this->number = (int)this->number % (int)value->number;
        }else{
            for(int i = 0; i < this->head.size(); i++){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type((int)this->head[i].number % (int)value->number);
                    return *temp;
                }
            }
        }
        return *this;

    }
    type &operator>( type value ){

        if(this->jsonType == JSON_NUMBER && value.jsonType == JSON_NUMBER ){

            bool temp_bool = this->number > value.number;

            if(temp_bool){

                this->jsonType = JSON_TRUE;
            }else{

                this->jsonType = JSON_FALSE;
            }

            this->boolean = temp_bool;
        }else{
            for(int i = 0; i < this->head.size() ; i++ ){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type(this->number > value.number);
                    return *temp;
                }
            }
        }
        return *this;
    }
    type &operator>(type *value){

        if(this->jsonType == JSON_NUMBER && value->jsonType == JSON_NUMBER ){

            bool temp_bool = this->number > value->number;

            if(temp_bool){

                this->jsonType = JSON_TRUE;
            }else{

                this->jsonType = JSON_FALSE;
            }

            this->boolean = temp_bool;
        }else{
            for(int i = 0; i < this->head.size() ; i++ ){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type(this->number > value->number);
                    return *temp;
                }
            }
        }
        return *this;
    }
    type &operator>=( type value ){

        if(this->jsonType == JSON_NUMBER && value.jsonType == JSON_NUMBER ){

            bool temp_bool = this->number >= value.number;

            if(temp_bool){

                this->jsonType = JSON_TRUE;
            }else{

                this->jsonType = JSON_FALSE;
            }

            this->boolean = temp_bool;
        }else{
            for(int i = 0; i < this->head.size() ; i++ ){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type(this->number >= value.number);
                    return *temp;
                }
            }
        }
        return *this;
    }
    type &operator>=(type *value){

        if(this->jsonType == JSON_NUMBER && value->jsonType == JSON_NUMBER ){

            bool temp_bool = this->number >= value->number;

            if(temp_bool){

                this->jsonType = JSON_TRUE;
            }else{

                this->jsonType = JSON_FALSE;
            }

            this->boolean = temp_bool;
        }else{
            for(int i = 0; i < this->head.size() ; i++ ){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type(this->number >= value->number);
                    return *temp;
                }
            }
        }
        return *this;
    }
    type &operator<( type value ){

        if(this->jsonType == JSON_NUMBER && value.jsonType == JSON_NUMBER ){

            bool temp_bool = this->number < value.number;

            if(temp_bool){

                this->jsonType = JSON_TRUE;
            }else{

                this->jsonType = JSON_FALSE;
            }

            this->boolean = temp_bool;
        }else{
            for(int i = 0; i < this->head.size() ; i++ ){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type(this->number < value.number);
                    return *temp;
                }
            }
        }
        return *this;
    }
    type &operator<(type *value){

        if(this->jsonType == JSON_NUMBER && value->jsonType == JSON_NUMBER ){

            bool temp_bool = this->number < value->number;

            if(temp_bool){

                this->jsonType = JSON_TRUE;
            }else{

                this->jsonType = JSON_FALSE;
            }

            this->boolean = temp_bool;
        }else{
            for(int i = 0; i < this->head.size() ; i++ ){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type(this->number < value->number);
                    return *temp;
                }
            }
        }
        return *this;
    }
    type &operator<=( type value ){

        if(this->jsonType == JSON_NUMBER && value.jsonType == JSON_NUMBER ){

            bool temp_bool = this->number <= value.number;

            if(temp_bool){

                this->jsonType = JSON_TRUE;
            }else{

                this->jsonType = JSON_FALSE;
            }

            this->boolean = temp_bool;
        }else{
            for(int i = 0; i < this->head.size() ; i++ ){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type(this->number <= value.number);
                    return *temp;
                }
            }
        }
        return *this;
    }
    type &operator<=(type *value){

        if(this->jsonType == JSON_NUMBER && value->jsonType == JSON_NUMBER ){

            bool temp_bool = this->number <= value->number;

            if(temp_bool){

                this->jsonType = JSON_TRUE;
            }else{

                this->jsonType = JSON_FALSE;
            }

            this->boolean = temp_bool;
        }else{
            for(int i = 0; i < this->head.size() ; i++ ){
                if(this->head[i].old_unused_flag == true){
                    this->head[i].old_unused_flag = false;
                    type *temp = new type(this->number <= value->number);
                    return *temp;
                }
            }
        }
        return *this;
    }
    type &operator+(type value){

        if(this->jsonType == JSON_STRING && value.jsonType == JSON_STRING){
            this->str = this->str + value.str;
        }else if(this->jsonType == JSON_NUMBER && value.jsonType == JSON_NUMBER){
            this->number = this->number + value.number;
        }else if(this->jsonType == JSON_ARRAY && value.jsonType == JSON_ARRAY){

            for(int i = 0; i < value.array.size() ; i++){
                this->array.push_back(value.array[i]);
            }

        }else if(this->jsonType == JSON_OBJECT && value.jsonType == JSON_OBJECT){
            for(int i = 0; i < value.head.size() ; i++){
                this->head.push_back(value.head[i]);
            }
        }

        return *this;
    }
    type &operator+(type *value){

        if(this->jsonType == JSON_STRING && value->jsonType == JSON_STRING){
            this->str = this->str + value->str;
        }else if(this->jsonType == JSON_NUMBER && value->jsonType == JSON_NUMBER){
            this->number = this->number + value->number;
        }else if(this->jsonType == JSON_ARRAY && value->jsonType == JSON_ARRAY){

            for(int i = 0; i < value->array.size() ; i++){
                this->array.push_back(value->array[i]);
            }

        }else if(this->jsonType == JSON_OBJECT && value->jsonType == JSON_OBJECT){
            for(int i = 0; i < value->head.size() ; i++){
                this->head.push_back(value->head[i]);
            }
        }

        return *this;
    }


    // BOOLEAN OPERATORS
    bool operator&&(type value){

        if((this->jsonType == JSON_FALSE || this->jsonType == JSON_TRUE) && (value.jsonType == JSON_FALSE || value.jsonType == JSON_TRUE)){
            if(this->boolean && value.boolean){
                return true;
            }else{
                return false;
            }
        }
    }
    bool operator&&(type *value){

        if((this->jsonType == JSON_FALSE || this->jsonType == JSON_TRUE) && (value->jsonType == JSON_FALSE || value->jsonType == JSON_TRUE)){
            if(this->boolean && value->boolean){
                return true;
            }else{
                return false;
            }
        }
    }
    bool operator||(type value){

        if((this->jsonType == JSON_FALSE || this->jsonType == JSON_TRUE) && (value.jsonType == JSON_FALSE || value.jsonType == JSON_TRUE)){
            if(this->boolean || value.boolean){
                return true;
            }else{
                return false;
            }
        }
    }
    bool operator||(type *value){

        if((this->jsonType == JSON_FALSE || this->jsonType == JSON_TRUE) && (value->jsonType == JSON_FALSE || value->jsonType == JSON_TRUE)){
            if(this->boolean || value->boolean){
                return true;
            }else{
                return false;
            }
        }
    }
    bool operator!(  ){

        if(this->jsonType == JSON_FALSE || this->jsonType == JSON_TRUE){
            return !this->boolean;                
        }else{
            
            return false;
        }
    }



    // EQUALITY OPERATORS

    bool checkType(type t1, type t2){
        if(t1.jsonType == t2.jsonType){
            if(t1.jsonType == JSON_NUMBER){
                if(t1.number == t2.number)
                    return true;                
            }else if(t1.jsonType == JSON_STRING){
                if(t1.str == t2.str)
                    return true;
            }else if(t1.jsonType == JSON_ARRAY){
                if(t1.array.size() == t2.array.size() && t1.array == t2.array)
                    return true;
            }else if(t1.jsonType == JSON_OBJECT){
                if(t1.head.size() == t2.head.size()){
                  //  cout<<"eimai sto limbo"<<endl;
                    for (int i = 0; i < t1.head.size(); i++){
                        if(t1.head[i].key.compare(t2.head[i].key) != 0 || !checkType(t1.head[i], t2.head[i]))
                            return true;
                    }
                    
                }

            }
        }    
    
    return false;
    }

    const bool operator==( type value ){

        bool ret_val = true;

        if((this->jsonType == JSON_TRUE && value.jsonType == JSON_FALSE) || (this->jsonType == JSON_FALSE && value.jsonType == JSON_TRUE))
            ret_val = false;
        else if(this->jsonType != value.jsonType ){
            cout<< "objects must be the SAME TYPE!"<< endl;
            return false;
        }
        else
            if(this->jsonType == JSON_NUMBER){
                if(this->number != value.number)
                    ret_val = false;

            }else if(this->jsonType == JSON_STRING){
                if(!value.str.compare(this->str))
                    ret_val = false;

            }else if(this->jsonType == JSON_ARRAY){
                if(this->array.size() != value.array.size())
                    ret_val = false;
                else
                    if(this->array != value.array)
                        ret_val = false;
                    
                
            }else if(this->jsonType == JSON_OBJECT){
                if(this->head.size() != value.head.size())
                    ret_val = false;
                else{
                    for (int i = 0; i < this->head.size(); i++){
                        if(this->head[i].key.compare(value.head[i].key) != 0 || !checkType(this->head[i], value.head[i])){
                            ret_val = false;
                            break;
                        }
                    }
                    
                }
                    
                
            }

        return ret_val;
    }
    const bool operator==( type *value ){

        bool ret_val = true;

        if((this->jsonType == JSON_TRUE && value->jsonType == JSON_FALSE) || (this->jsonType == JSON_FALSE && value->jsonType == JSON_TRUE))
            ret_val = false;
        else if(this->jsonType != value->jsonType ){
            cout<< "objects must be the SAME TYPE!"<< endl;
            return false;
        }
        else
            if(this->jsonType == JSON_NUMBER){
                if(this->number != value->number)
                    ret_val = false;

            }else if(this->jsonType == JSON_STRING){
                if(!value->str.compare(this->str))
                    ret_val = false;

            }else if(this->jsonType == JSON_ARRAY){
                if(this->array.size() != value->array.size())
                    ret_val = false;
                else
                    if(this->array != value->array)
                        ret_val = false;
                    
                
            }else if(this->jsonType == JSON_OBJECT){
                if(this->head.size() != value->head.size())
                    ret_val = false;
                else{
                    for (int i = 0; i < this->head.size(); i++){
                        if(this->head[i].key.compare(value->head[i].key) != 0 || !checkType(this->head[i], value->head[i])){
                            ret_val = false;
                            break;
                        }
                    }
                    
                }
                    
                
            }

        return ret_val;
    }
    const bool operator!=( type value ){

        bool ret_val = true;

        if((this->jsonType == JSON_TRUE && value.jsonType == JSON_FALSE) || (this->jsonType == JSON_FALSE && value.jsonType == JSON_TRUE))
            ret_val = false;
        else if(this->jsonType != value.jsonType ){
            cout<< "objects must be the SAME TYPE!"<< endl;
            return false;
        }
        else
            if(this->jsonType == JSON_NUMBER){
                if(this->number != value.number)
                    ret_val = false;

            }else if(this->jsonType == JSON_STRING){
                if(!value.str.compare(this->str))
                    ret_val = false;

            }else if(this->jsonType == JSON_ARRAY){
                if(this->array.size() != value.array.size())
                    ret_val = false;
                else
                    if(this->array != value.array)
                        ret_val = false;
                    
                
            }else if(this->jsonType == JSON_OBJECT){
                if(this->head.size() != value.head.size())
                    ret_val = false;
                else{
                    for (int i = 0; i < this->head.size(); i++){
                        if(this->head[i].key.compare(value.head[i].key) != 0 || !checkType(this->head[i], value.head[i])){
                            ret_val = false;
                            break;
                        }
                    }
                    
                }
                    
                
            }

        return !ret_val;
    }
    const bool operator!=( type *value ){

        bool ret_val = true;

        if((this->jsonType == JSON_TRUE && value->jsonType == JSON_FALSE) || (this->jsonType == JSON_FALSE && value->jsonType == JSON_TRUE))
            ret_val = false;
        else if(this->jsonType != value->jsonType ){
            cout<< "objects must be the SAME TYPE!"<< endl;
            return false;
        }
        else
            if(this->jsonType == JSON_NUMBER){
                if(this->number != value->number)
                    ret_val = false;

            }else if(this->jsonType == JSON_STRING){
                if(!value->str.compare(this->str))
                    ret_val = false;

            }else if(this->jsonType == JSON_ARRAY){
                if(this->array.size() != value->array.size())
                    ret_val = false;
                else
                    if(this->array != value->array)
                        ret_val = false;
                    
                
            }else if(this->jsonType == JSON_OBJECT){
                if(this->head.size() != value->head.size())
                    ret_val = false;
                else{
                    for (int i = 0; i < this->head.size(); i++){
                        if(this->head[i].key.compare(value->head[i].key) != 0 || !checkType(this->head[i], value->head[i])){
                            ret_val = false;
                            break;
                        }
                    }
                    
                }
                    
                
            }

        return !ret_val;
    }


    // FUNCTIONS
    int SIZE_OF_MACRO(){

        if(this->jsonType == JSON_ARRAY){
            return (int)this->array.size();
        }else if(this->jsonType == JSON_OBJECT){
            return (int)this->head.size();
        }else{
            cout<< "object must be type 'object' or 'array"<<endl;
            return false;
        }
   
    }
    bool IS_EMPTY_MACRO(){
        if(this->jsonType == JSON_ARRAY){
            if(this->array.size() == 0){
                return true;
            }else{
                return false;
            }
        }else if(this->jsonType == JSON_OBJECT){
            if(this->head.size() == 0){
                return true;
            }else{
                return false;
            }
        }else{
            cout<< "object must be type 'object' or 'array"<<endl;
            return false;
        }
 
    }
    bool HAS_KEY_MACRO(string key){
        
        if(this->jsonType != JSON_OBJECT){
            return false;
        }else{
            for(int i; i< this->head.size(); i++){
                if(!this->head[i].key.compare(key)){
                    return true;
                }
                
            }
        }

    return false;
    } 
    string TYPE_OF_MACRO(){

        if(this->jsonType == JSON_STRING){
            return "string";
        }else if(this->jsonType == JSON_NUMBER){
            return "number";
        }else if(this->jsonType == JSON_TRUE || this->jsonType == JSON_FALSE){
            return "boolean";
        }else if(this->jsonType == JSON_ARRAY){
            return "array";
        }else if(this->jsonType == JSON_OBJECT){
            return "object";
        }else{
            return "NULL";
        }

    }
    

    bool isArrayEmpty(){
        if(this->array.size() == 0)
            return true;
        else
            return false;
    }
    void reset(){

        this->str = "";
        this->number = ORIAKA_INT_MAX;
        this->boolean = false;
        this->jsonType = -1;
        this->head.clear();
        this->array.clear();

        old_unused_flag = false;

    }



private:
    vector<type>            head;
    vector<type>            temp_head;
    vector<float>           array;
    string str              = "";
    string key              = "";
    float number            = ORIAKA_INT_MAX;
    int jsonType            = -1;
    bool boolean;
    int special_treatment   = 0;
            
    bool old_unused_flag  = false;
};
