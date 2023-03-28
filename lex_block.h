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

   typedef State(Lex_block_mb::*funct_ptr)();

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

   const size_t m_state_number = 19;
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
   std::map<State, std::map<symbol_lexem, funct_ptr>> m_func_table;    //������� ��������� �����������


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

   void init_states();

   void init_func_table();

   void DA1D();
   void DA2D();
   void DA3D();
   void DA1E();
   void DA1ECYCLE();

   //������, �������� ���������� �������

   State e_A1() { return m_collect_of_states["A1"]; }
   State e_A2() { return m_collect_of_states["A2"]; }
   State e_A3() { return m_collect_of_states["A3"]; }
   State e_B1() { return m_collect_of_states["B1"]; }
   State e_C1() { return m_collect_of_states["C1"]; }
   State e_C2() { return m_collect_of_states["C2"]; }
   State e_D1() { return m_collect_of_states["D1"]; }
   State e_D2() { return m_collect_of_states["D2"]; }
   State e_D3() { return m_collect_of_states["D3"]; }
   State e_D4() { return m_collect_of_states["D4"]; }
   State e_D5() { return m_collect_of_states["D5"]; }
   State e_D6() { return m_collect_of_states["D6"]; }
   State e_E1() { return m_collect_of_states["E1"]; }
   State e_E2() { return m_collect_of_states["E2"]; }
   State e_F1() { return m_collect_of_states["F1"]; }
   State e_F2() { return m_collect_of_states["F2"]; }
   State e_F3() { return m_collect_of_states["F3"]; }
   State e_G1() { return m_collect_of_states["G1"]; }
   State e_H1() { return m_collect_of_states["H1"]; }

   State A1a();
   State A1b();
   State A1c();
   State A1d();
   State A1e();

   State A2a();
   State A2b();
   State A2c();
   State A2d();
   State A2e();
   State A2f();
   State A2g();
   State A2h();
   State A2i();
   State A2j();
   State A2k();
   State A2m();
   State A2n();
   State A2o();
   State A2p();
   State A2q();
   State A2r();
   State A2s();
   State A2t();
   State A2u();

   State A3a();
   State A3b();
   State A3c();
   State A3d();
   State A3e();
   State A3f();
   State A3g();


   State B1a();
   State B1b();
   State B1c();
   State B1d();
   State B1e();

   State C1a();

   State C2a();
   State C2b();
   State C2c();
   State C2d();

   State D1a();
   State D1b();
   State D1c();

   State D2a();
   State D2b();
   State D2c();

   State D3a();

   State D4a();

   State D5a();
   State D5b();
   State D5c();

   State D6a();

   State E1a();
   State E1b();

   State E2a();
   State E2b();
   State E2c();

   State F1a();
   State F1b();

   State F2a();

   State F3a();

   State G1a();

   State H1a();
   State H1b();
   State H1c();
   State H1d();
   State H1e();
   State H1f();

   State M1();
   State M2();
   State M3();

   State EXIT1();
   State EXIT2();
   State EXIT3();
   State EXIT4();
   State EXIT5();
   State EXIT6();


};