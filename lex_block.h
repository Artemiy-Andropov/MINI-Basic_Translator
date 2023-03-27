#pragma once
#include<iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include "det_analizer.h"

class Lex_block_mb : public det_analizer
{
public:
   //enum class symbol_lexem
   //{
   //   sl_letter, 
   //   sl_digit, 
   //   sl_aur_op, 
   //   sl_relat,
   //   sl_op_brace,
   //   sl_cls_brace,
   //   sl_dot,
   //   sl_space,
   //   sl_lf,
   //   sl_eof,
   //   sl_error
   //};
   //enum class Lexem {
   //   lex_line, lex_operand, lex_aur_oper,
   //   lex_relation, lex_next, lex_let,
   //   lex_for, lex_goto, lex_gosub,
   //   lex_op_brace, lex_cls_brace, lex_if, 
   //   lex_return, lex_end, lex_to,
   //   lex_step, lex_rem, lex_error,
   //   lex_eof
   //};

   Lex_block_mb(std::string filename);


   virtual void parse();

   ~Lex_block_mb()
   {
      m_file.close();
   }

protected:
   //��������� ���� ����������� �� ������ det_analizer:
   //std::map<State, std::map<symbol_lexem, funct_ptr>> m_func_table;    //������� ��������� �����������
   //std::list<std::tuple<Lexem, long long int, size_t>> m_lexem_list; //������ ������ �����������
   //std::map<std::string, double> m_name_table;                       //������� ���
   //State m_curr_state;                                               //������� ��������� �����������
   //inp_symbol m_curr_sym;                                            //������� ������� ������
   //std::fstream m_file;                                              //������� �������� �����

   const size_t m_state_number = 23;
   const size_t m_class_number = 10;

   Lexem m_reg_class;               //������� ������. ������ ��� �������� ������ �������
   long long int m_reg_nt_pointer;  //������� ���������. �������� ��������� ��� ������ PUSH � POP
   size_t m_reg_relation;           //������� ���������. ������ ���������� � ������ ������� ���������
   double m_reg_number;             // ������� �����. ������������ ��� ���������� ��������
   size_t m_reg_order;              // ������� �������
   size_t m_reg_counter;            // ������� ��������
   size_t m_reg_is_negative;        // ������� ����� �����
   size_t m_reg_line_num = 1;       // ����� ������. ������ ����� ������� ������ � ���������.
   std::string m_reg_var_name;      // ������� ����������. ����������� ��� ����������
   size_t m_reg_detection = 0;      //������� �����������. ������ ����� ������� � ������� ����������� ��� ������ �������� ����.
   size_t m_reg_value;              // ������� ��������. ������ �������� ������

   std::map<char, int> m_beg_vector;   // ��������� ������

   std::vector<std::tuple<char, int, funct_ptr>> m_detect_table; // ������� �����������

   virtual det_analizer::inp_symbol transliterator(int sym);


private:

   void fill_lexems();

   void fill_symbol_lexems();
   /*
   * @brief ���������� ��������� � ��������� m_name_table
   */
   void add_constant();
   /*
   * @brief ���������� ���������� � ��������� m_name_table
   */
   void add_variable();

   void create_lexem();

   /*
   * @brief �����, ����������� ��������� ������ ������ �����-������
   */
   void init_beg_vect();

   /*
   * @bried �����, ����������� ������� ����������� �������� �����-�������-������������
   */
   void init_detect_table();

   void init_func_table();

};