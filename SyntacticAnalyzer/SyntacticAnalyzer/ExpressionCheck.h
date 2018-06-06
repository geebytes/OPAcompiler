///=================================================================================================
/// \file ExpressionCheck.h
///
/// \brief �������ڱ���ʽ������
///=================================================================================================

#ifndef EXPRESSIONCHECK_H
#define EXPRESSIONCHECK_H
#include "PriorityTable.h"
#include<vector>
#include<set>
#include <map>
#include <stack>
using namespace std;

///=================================================================================================
/// \enum ERROR_CODE
///
/// \brief ����ʽ�������
///
///=================================================================================================

enum ERROR_CODE {

    ///< �������ȱ�ٱ���ʽ
    EXPRESSION_ERROR,

    ///< ����ʽ��ȱ�������
    EXP_NO_OPERATOR,

    ///< ���ż��ޱ���ʽ
    BRACKETS_NO_EXP,

    ///< �Ƿ�������
    INVALID_LEFT_BRACKET,

    ///< ��ȷ
    DEFECT_OPERATOR, OK,

    ///< �Ƿ�������
    INVALID_RIGHT_BRACKET
};

///=================================================================================================
/// \class ExpressionCheck
///
/// \brief �ṩ������ʽ�Ϸ��ԵĹ���
///
/// \date 2018/6/3
///=================================================================================================

class ExpressionCheck {
  public:
    ExpressionCheck();
    //��ȡ�ķ�
    void get_grammar(std::vector<std::string> grammars);

    //��ȡ�ս��
    void get_terminal_symbol(set<char> terminal_symbols);

    //�������ȹ�ϵ��
    void make_priority_table();

    //������ʽ
    int check_expression(string expression);

    //��ӡ������Ϣ
    void print_info();

    //��ӡ����ջ��״̬
    void print_stack();

    //��ӡ��������
    void print_step();

    //��ӡ������Ϣ
    void print_error();

    //��������
    void reset();

    //��ȡ��������
    map<int, vector<string>> get_setp();

    //��ȡ������Ϣ
    map<int, string> get_error();

    //��ȡ���ȹ�ϵ��
    map<pair<char, char>, char> get_priority_table();

    //��ȡLAST��
    map<char, set<char>> get_last();

    //��ȡFIRST��
    map<char, set<char>> get_first();

    //��ȡ����ջ��״̬
    string get_stack_status();
    ~ExpressionCheck();
  private:

    /// \brief ���ȹ�ϵ��
    PriorityTable priority_table;

    /// \brief ����ʽ
    vector<std::string> grammars;

    /// \brief ������Ϣ
    vector<std::string>error_info;

    /// \brief �������̵���Ϣ
    map<int, vector<string>> analysis_info;

    /// \brief �����¼
    map<int, string> error_record;

    /// \brief �ս������
    set<char> terminal_symbols;

    /// \brief ����ջ
    stack<char> symbols_stack;

    /// \brief ���ȹ�ϵ��
    map<pair<char, char>, char>table;

    /// \brief ����ʽ
    map<char, vector<string>>productions;

    /// \brief ��׼����Ĳ���ʽ���Ҳ�
    set<string> std_left;

    /// \brief �����ض���
    string left_prime_phrase;

    /// \brief ����ʽ
    string expression_str;

    /// \brief ����ʽ�ַ�����
    int expression_index;

    /// \brief ���������
    int setp;

    /// \brief �ض���
    string left_phrase;

    /// \brief �Ƿ��ƽ�
    bool is_move;

    //�����ض���ļ��
    int check_error(string left_prime_phrase, char normalize_char);

    //�������ս��
    char skip_no_terminal(char top_value);

    //��Լ
    char normalization(char top_value, char exp_value);

    //����ʽ��׼��
    void production_to_std();

    //���ݲ���ʽ�Ҳ�ƥ�����ʽ��
    bool match_production_left(string right_str);

    //�����������
    void save_analysis_step(int index, char prioity, string left, string act);

};
#endif

