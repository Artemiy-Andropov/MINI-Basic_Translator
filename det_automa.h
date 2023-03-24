#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

//��������� ��������� ��������
enum class state 
{
   q0, q1, q2, q3, qe
};

//������� ��������� ��������
enum class symbol
{
   letter_a, letter_b
};

//��������� inp_symbol - ������������ ������ � ��� �������������� � �������� ��������� ��������
struct inp_symbol
{
   int s_value;
   symbol s_class;
};

// ����� det_automa - �������� �������
class det_automa
{
protected:
   size_t m_state_num;                              //����� ��������� (��� ����������� ������)
   size_t m_sym_num;                                //����� �������� �������� �������� 
   state  m_curr_state;                             //������� ��������� ��������
   inp_symbol m_curr_sym;                           //������� ������
   std::vector<std::vector<state>> m_trans_table;   //������� ���������
   std::vector<state> m_finite_states;              //������ �������� ���������
   std::fstream m_file;                             //��������� �� ����
   std::string m_filename;

   /*
   * @brief ����������� ����� �������������� �������� �������
   * @param int sym
   * @returns ��������� ���� inp_symbol
   */
   virtual inp_symbol transliterator(int sym); 

   /*
   * @brief ����������� ����� ����������� ��������� ��������
   * @param const det_automa& obj
   */
   virtual void copy_det_automa(const det_automa& obj);


public:

   /*
   * @brief ����������� ������ "�������� �������". �� ���� �������� ��������� ���������, ������� ���������, ������ ����������� ��������� � ��� ����� � ������� ������.
   * @param state start_state, std::vector<std::vector<state>> trans_table, std::vector<state> finite_states, std::string m_filename
   * @returns ������ ������ "�������� �������"
   */
   det_automa(const state start_state, const std::vector<std::vector<state>> trans_table, const std::vector<state> finite_states, const std::string filename);

   det_automa();


   /*
   * @brief ����������� ����������� ������ "�������� �������". �� ���� �������� ��������� ���������, ������� ���������, ������ ����������� ��������� � ��� ����� � ������� ������.
   * @param det_automa& obj
   * @returns ������ ������ "�������� �������"
   */
   det_automa(const det_automa& obj);

   det_automa& operator=(const det_automa& obj);

   void parse();

   ~det_automa() { m_file.close(); }

   //
};




class automa1 : public det_automa
{
private:
   virtual inp_symbol transliterator(int sym)
   {
      inp_symbol curr_sym;
      switch (sym)
      {
      case 97:
      {
         curr_sym.s_value = 97;
         curr_sym.s_class = symbol::letter_a;
         return curr_sym;
      }
      case 98:
      {
         curr_sym.s_value = 97;
         curr_sym.s_class = symbol::letter_b;
         return curr_sym;
      }
      default:
      {
         exit(1);
      }
      }
   }

public:
   automa1(const state start_state, const std::vector<std::vector<state>> trans_table, const std::vector<state> finite_states, const std::string filename) //: det_automa(start_state, trans_table, finite_states, filename) {}
   {
      m_state_num = trans_table.capacity();
      m_sym_num = trans_table[0].capacity();
      m_curr_state = start_state;
      m_filename = filename;
      m_file = std::fstream(m_filename);
      if (!m_file)
      {
         std::cout << "couldn't open file " << filename << std::endl;
         return;
      }

      m_curr_sym = transliterator(m_file.get());
      m_trans_table = trans_table;
      m_finite_states = finite_states;
   }

   ~automa1(){ m_file.close(); }
};