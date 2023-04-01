#pragma once
#include<iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <list>

//����� "��������� ��������� �����������"
class State
{
public:
   std::string m_name;  //��� ���������
   size_t m_id;         //���������� ������������� ���������

   //����������� �� ��������� ����������� ��������� ������ id
   State();
      
   //���������� � ����������� ����������� ��������� id �� ������� ������
   State(std::string name, size_t id);

   //�������� ������������, ���������� id ������� obj � ������ this
   State& operator=(const State& obj);

   //�������� ���������, ������������ id ���� ���������
   bool operator==(const State& obj);

   //�������� ��������� "������", ������������ id ���� �������� � ���. ��������� <
   friend bool operator<(const State& obj1, const State& obj2);    

   ~State() {}
};


// ����������� ����� "�������� ����������� ����������"
class Determ_analizer
{
public:
   /*
   * @brief ����������� ������� �������� - ��������� �������� �� ������� ��������� � ����������� �� �������� �������
   */
   virtual void parse() = 0;

   //������������ "���������� �������" � "�������"
   class Symbol_lexem 
   {
   public:
      std::string m_name;
      size_t m_id;
      Symbol_lexem(const char* str = "", size_t id = -1) 
      { 
         m_name = str; 
         m_id = id;
      }
      Symbol_lexem& operator=(const Symbol_lexem& obj) 
      {
         m_name = obj.m_name;
         m_id = obj.m_id;
         return *this;
      }
      friend bool operator<(const Symbol_lexem& obj1, const Symbol_lexem& obj2);
   };
   class Lexem
   {
   public:
      std::string m_name;
      size_t m_id;
      Lexem(std::string str = "", size_t id = -1) { m_name = str; m_id = id; }
      Lexem& operator=(const char* str) { m_name = str; return *this; }
      friend bool operator<(const Lexem& obj1, const Lexem& obj2);

   };

   //��������� Input_symbol - ������������ ������ � ��� �������������� � �������� ��������� ��������
   struct Input_symbol
   {
      int s_value; //ASCII - ��� �������
      Symbol_lexem s_class; //�������������� � ��������
      Input_symbol() { s_value = -1; s_class = ""; }
      //friend bool operator<(Input_symbol& sym1, Input_symbol& sym2);
   };

   struct variable
   {
      std::string var_name;
      double var_value = 0;
   };

protected:
   std::list<std::tuple<Lexem, long long int, size_t>> m_lexem_list; //������ ������ �����������
   std::map<std::string, variable> m_name_table;                       //������� ���
   State m_curr_state;                                               //������� ��������� �����������
   Input_symbol m_curr_sym;                                            //������� ������� ������
   std::fstream m_file;                                              //������� �������� �����

   std::map<std::string, Symbol_lexem> m_collection_of_Symlex;
   std::map<std::string, Lexem> m_collection_of_Lex;
   std::map<std::string, State>  m_collection_of_States;

   /*
   * @brief ����������� ������� ��������������. ������� �� ���������, ������������ � ����������� ������ ���������������.
   * @param int sym
   * @returns ������ ��������� Input_symbol
   */
   virtual Input_symbol transliterator(int sym) = 0;
 
};

