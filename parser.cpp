// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 59 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"

    #include "driver.hh"
    #include "location.hh"

    #include "help/Visitor.h"
    #include "help/Program.h"
    #include "help/Types/Boolean.h"
    #include "help/Types/Integer.h"
    #include "help/Types/String.h"
    #include "help/Expressions/NotExpression.h"
    #include "help/Expressions/AndExpression.h"
    #include "help/Expressions/OrExpression.h"
    #include "help/Expressions/EqualExpression.h"
    #include "help/Expressions/NotEqualExpression.h"
    #include "help/Expressions/GreaterExpression.h"
    #include "help/Expressions/GreaterEqExpression.h"
    #include "help/Expressions/LessExpression.h"
    #include "help/Expressions/LessEqExpression.h"
    #include "help/Expressions/PlusExpression.h"
    #include "help/Expressions/MinusExpression.h"
    #include "help/Expressions/UnaryMinusExpression.h"
    #include "help/Expressions/MulExpression.h"
    #include "help/Expressions/ModExpression.h"
    #include "help/Expressions/DivExpression.h"
    #include "help/Expressions/IDExpression.h"

    #include "help/Statements/WhileStatement.h"
    #include "help/Statements/IfStatement.h"
    #include "help/Statements/IfElseStatement.h"
    #include "help/Statements/ForStatement.h"
    #include "help/Statements/Iterator.h"
    #include "help/Statements/VariableDeclaration.h"
    #include "help/Statements/VariableDeclInit.h"
    #include "help/Statements/AssignmentStatement.h"
    #include "help/Statements/ExpressionList.h"
    #include "help/Statements/PrintStatement.h"
    #include "help/Statements/Interruptions/BreakStatement.h"
    #include "help/Statements/Interruptions/ContinueStatement.h"

    /* Redefine parser to use our function from scanner */
    static yy::parser::symbol_type yylex(Scanner &scanner) {
        return scanner.ScanToken();
    }

#line 91 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 183 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"

  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.YY_MOVE_OR_COPY< std::shared_ptr<ExpressionList> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_iterator: // iterator
        value.YY_MOVE_OR_COPY< std::shared_ptr<Iterator> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_print_statement: // print_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<PrintStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.YY_MOVE_OR_COPY< std::shared_ptr<Program> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_let_statement: // let_statement
      case symbol_kind::S_mut_let_statement: // mut_let_statement
      case symbol_kind::S_const_let_statement: // const_let_statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
        value.YY_MOVE_OR_COPY< std::shared_ptr<Statements> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRLITERAL: // "string_literal"
      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.move< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::shared_ptr<ExpressionList> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_iterator: // iterator
        value.move< std::shared_ptr<Iterator> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_print_statement: // print_statement
        value.move< std::shared_ptr<PrintStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.move< std::shared_ptr<Program> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_let_statement: // let_statement
      case symbol_kind::S_mut_let_statement: // mut_let_statement
      case symbol_kind::S_const_let_statement: // const_let_statement
        value.move< std::shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
        value.move< std::shared_ptr<Statements> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRLITERAL: // "string_literal"
      case symbol_kind::S_type: // type
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "number"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_expression: // expression
        value.copy< std::shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.copy< std::shared_ptr<ExpressionList> > (that.value);
        break;

      case symbol_kind::S_iterator: // iterator
        value.copy< std::shared_ptr<Iterator> > (that.value);
        break;

      case symbol_kind::S_print_statement: // print_statement
        value.copy< std::shared_ptr<PrintStatement> > (that.value);
        break;

      case symbol_kind::S_program: // program
        value.copy< std::shared_ptr<Program> > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_let_statement: // let_statement
      case symbol_kind::S_mut_let_statement: // mut_let_statement
      case symbol_kind::S_const_let_statement: // const_let_statement
        value.copy< std::shared_ptr<Statement> > (that.value);
        break;

      case symbol_kind::S_statements: // statements
        value.copy< std::shared_ptr<Statements> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRLITERAL: // "string_literal"
      case symbol_kind::S_type: // type
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_expression: // expression
        value.move< std::shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::shared_ptr<ExpressionList> > (that.value);
        break;

      case symbol_kind::S_iterator: // iterator
        value.move< std::shared_ptr<Iterator> > (that.value);
        break;

      case symbol_kind::S_print_statement: // print_statement
        value.move< std::shared_ptr<PrintStatement> > (that.value);
        break;

      case symbol_kind::S_program: // program
        value.move< std::shared_ptr<Program> > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_let_statement: // let_statement
      case symbol_kind::S_mut_let_statement: // mut_let_statement
      case symbol_kind::S_const_let_statement: // const_let_statement
        value.move< std::shared_ptr<Statement> > (that.value);
        break;

      case symbol_kind::S_statements: // statements
        value.move< std::shared_ptr<Statements> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRLITERAL: // "string_literal"
      case symbol_kind::S_type: // type
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_IDENTIFIER: // "identifier"
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::string > (); }
#line 503 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_NUMBER: // "number"
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < int > (); }
#line 509 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_STRLITERAL: // "string_literal"
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::string > (); }
#line 515 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_program: // program
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::shared_ptr<Program> > (); }
#line 521 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_statements: // statements
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::shared_ptr<Statements> > (); }
#line 527 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_statement: // statement
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::shared_ptr<Statement> > (); }
#line 533 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_print_statement: // print_statement
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::shared_ptr<PrintStatement> > (); }
#line 539 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_if_statement: // if_statement
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::shared_ptr<Statement> > (); }
#line 545 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_let_statement: // let_statement
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::shared_ptr<Statement> > (); }
#line 551 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_mut_let_statement: // mut_let_statement
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::shared_ptr<Statement> > (); }
#line 557 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_const_let_statement: // const_let_statement
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::shared_ptr<Statement> > (); }
#line 563 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_iterator: // iterator
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::shared_ptr<Iterator> > (); }
#line 569 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_type: // type
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::string > (); }
#line 575 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_expression: // expression
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::shared_ptr<Expression> > (); }
#line 581 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      case symbol_kind::S_expression_list: // expression_list
#line 178 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 { yyo << yysym.value.template as < std::shared_ptr<ExpressionList> > (); }
#line 587 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_NUMBER: // "number"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< std::shared_ptr<Expression> > ();
        break;

      case symbol_kind::S_expression_list: // expression_list
        yylhs.value.emplace< std::shared_ptr<ExpressionList> > ();
        break;

      case symbol_kind::S_iterator: // iterator
        yylhs.value.emplace< std::shared_ptr<Iterator> > ();
        break;

      case symbol_kind::S_print_statement: // print_statement
        yylhs.value.emplace< std::shared_ptr<PrintStatement> > ();
        break;

      case symbol_kind::S_program: // program
        yylhs.value.emplace< std::shared_ptr<Program> > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_let_statement: // let_statement
      case symbol_kind::S_mut_let_statement: // mut_let_statement
      case symbol_kind::S_const_let_statement: // const_let_statement
        yylhs.value.emplace< std::shared_ptr<Statement> > ();
        break;

      case symbol_kind::S_statements: // statements
        yylhs.value.emplace< std::shared_ptr<Statements> > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_STRLITERAL: // "string_literal"
      case symbol_kind::S_type: // type
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: "fn" "main" "(" ")" "{" statements "}"
#line 184 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                           {
    yylhs.value.as < std::shared_ptr<Program> > () = std::make_shared<Program>(yystack_[1].value.as < std::shared_ptr<Statements> > ());
    driver.program = yylhs.value.as < std::shared_ptr<Program> > ();
    }
#line 885 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 3: // statements: %empty
#line 190 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
           {yylhs.value.as < std::shared_ptr<Statements> > () = std::make_shared<Statements>();}
#line 891 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 4: // statements: statements statement
#line 191 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                           {yystack_[1].value.as < std::shared_ptr<Statements> > ()->add_statement(yystack_[0].value.as < std::shared_ptr<Statement> > ()); yylhs.value.as < std::shared_ptr<Statements> > () = yystack_[1].value.as < std::shared_ptr<Statements> > ();}
#line 897 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 5: // statement: "{" statements "}"
#line 194 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                       {yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[1].value.as < std::shared_ptr<Statements> > ();}
#line 903 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 6: // statement: ";"
#line 195 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
          {}
#line 909 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 7: // statement: "break"
#line 196 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
              {yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<BreakStatement>();}
#line 915 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 8: // statement: "continue"
#line 197 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 {yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<ContinueStatement>();}
#line 921 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 9: // statement: print_statement
#line 198 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                      {yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[0].value.as < std::shared_ptr<PrintStatement> > ();}
#line 927 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 10: // statement: let_statement
#line 199 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                    {yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[0].value.as < std::shared_ptr<Statement> > ();}
#line 933 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 11: // statement: "identifier" "=" expression ";"
#line 200 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                      {yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<AssignmentStatement>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<Expression> > ());}
#line 939 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 12: // statement: expression ";"
#line 201 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                     {yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[1].value.as < std::shared_ptr<Expression> > ();}
#line 945 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 13: // statement: if_statement
#line 202 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                   {yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[0].value.as < std::shared_ptr<Statement> > ();}
#line 951 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 14: // statement: "while" expression "{" statements "}"
#line 203 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                            {yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<WhileStatement>(yystack_[3].value.as < std::shared_ptr<Expression> > (), yystack_[1].value.as < std::shared_ptr<Statements> > ());}
#line 957 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 15: // statement: "for" "identifier" "in" iterator "{" statements "}"
#line 204 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                                          {yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<ForStatement>(yystack_[5].value.as < std::string > (), yystack_[3].value.as < std::shared_ptr<Iterator> > (), yystack_[1].value.as < std::shared_ptr<Statements> > ());}
#line 963 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 16: // statement: "return" ";"
#line 205 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                   {}
#line 969 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 17: // print_statement: "print!" "(" "string_literal" expression_list ")" ";"
#line 208 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                                          {yylhs.value.as < std::shared_ptr<PrintStatement> > () = std::make_shared<PrintStatement>(yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::shared_ptr<ExpressionList> > (), false);}
#line 975 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 18: // print_statement: "println!" "(" "string_literal" expression_list ")" ";"
#line 209 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                                              {yylhs.value.as < std::shared_ptr<PrintStatement> > () = std::make_shared<PrintStatement>(yystack_[3].value.as < std::string > (), yystack_[2].value.as < std::shared_ptr<ExpressionList> > (), true);}
#line 981 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 19: // if_statement: "if" expression "{" statements "}"
#line 212 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                       {yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<IfStatement>(yystack_[3].value.as < std::shared_ptr<Expression> > (), yystack_[1].value.as < std::shared_ptr<Statements> > ());}
#line 987 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 20: // if_statement: "if" expression "{" statements "}" "else" if_statement
#line 213 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                                             {yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<IfElseStatement>(yystack_[5].value.as < std::shared_ptr<Expression> > (), yystack_[3].value.as < std::shared_ptr<Statements> > (), yystack_[0].value.as < std::shared_ptr<Statement> > ());}
#line 993 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 21: // if_statement: "if" expression "{" statements "}" "else" "{" statements "}"
#line 214 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                                                   {yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<IfElseStatement>(yystack_[7].value.as < std::shared_ptr<Expression> > (), yystack_[5].value.as < std::shared_ptr<Statements> > (), yystack_[1].value.as < std::shared_ptr<Statements> > ());}
#line 999 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 22: // let_statement: const_let_statement
#line 217 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                        {yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[0].value.as < std::shared_ptr<Statement> > ();}
#line 1005 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 23: // let_statement: mut_let_statement
#line 218 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                        {yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[0].value.as < std::shared_ptr<Statement> > ();}
#line 1011 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 24: // mut_let_statement: "let" "mut" "identifier" ":" type "=" expression ";"
#line 221 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                                         {yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<VariableDeclInit>(yystack_[5].value.as < std::string > (), yystack_[3].value.as < std::string > (), false, yystack_[1].value.as < std::shared_ptr<Expression> > ());}
#line 1017 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 25: // mut_let_statement: "let" "mut" "identifier" ":" type ";"
#line 222 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                            {yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<VariableDeclaration>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::string > ());}
#line 1023 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 26: // const_let_statement: "let" "identifier" ":" type "=" expression ";"
#line 225 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                                   {yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<VariableDeclInit>(yystack_[5].value.as < std::string > (), yystack_[3].value.as < std::string > (), true, yystack_[1].value.as < std::shared_ptr<Expression> > ());}
#line 1029 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 27: // iterator: expression ".." expression
#line 228 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                               {}
#line 1035 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 28: // iterator: expression "..=" expression
#line 229 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                  {}
#line 1041 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 29: // iterator: expression
#line 230 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                 {}
#line 1047 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 30: // type: "i32"
#line 233 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
          {yylhs.value.as < std::string > () = "i32";}
#line 1053 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 31: // type: "String"
#line 234 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
               {yylhs.value.as < std::string > () = "String";}
#line 1059 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 32: // type: "bool"
#line 235 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
             {yylhs.value.as < std::string > () = "bool";}
#line 1065 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 33: // expression: "number"
#line 238 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
             {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Integer> (yystack_[0].value.as < int > ());}
#line 1071 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 34: // expression: "false"
#line 239 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
              {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Boolean> (false);}
#line 1077 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 35: // expression: "true"
#line 240 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
             {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Boolean> (true);}
#line 1083 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 36: // expression: "identifier"
#line 241 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                   {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<IDExpression> (yystack_[0].value.as < std::string > ());}
#line 1089 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 37: // expression: "!" expression
#line 242 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                     {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<NotExpression> (yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1095 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 38: // expression: "(" expression ")"
#line 243 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                         {yylhs.value.as < std::shared_ptr<Expression> > () = yystack_[1].value.as < std::shared_ptr<Expression> > ();}
#line 1101 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 39: // expression: "-" expression
#line 244 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                     {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<UnaryMinusExpression> (yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1107 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 40: // expression: expression "<" expression
#line 245 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<LessExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1113 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 41: // expression: expression "<=" expression
#line 246 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                 {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<LessEqExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1119 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 42: // expression: expression "==" expression
#line 247 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                 {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<EqualExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1125 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 43: // expression: expression "!=" expression
#line 248 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                 {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<NotEqualExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1131 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 44: // expression: expression ">=" expression
#line 249 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                 {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<GreaterEqExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1137 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 45: // expression: expression ">" expression
#line 250 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<GreaterExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1143 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 46: // expression: expression "&&" expression
#line 251 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                 {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<AndExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1149 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 47: // expression: expression "||" expression
#line 252 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                 {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<OrExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1155 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 48: // expression: expression "*" expression
#line 253 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<MulExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1161 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 49: // expression: expression "/" expression
#line 254 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<DivExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1167 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 50: // expression: expression "%" expression
#line 255 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<ModExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1173 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 51: // expression: expression "+" expression
#line 256 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<PlusExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1179 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 52: // expression: expression "-" expression
#line 257 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<MinusExpression> (yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1185 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 53: // expression_list: %empty
#line 260 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
           {yylhs.value.as < std::shared_ptr<ExpressionList> > () = std::make_shared<ExpressionList>();}
#line 1191 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;

  case 54: // expression_list: expression_list "," expression
#line 261 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"
                                     {yystack_[2].value.as < std::shared_ptr<ExpressionList> > ()->add_expression(yystack_[0].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<ExpressionList> > () = yystack_[2].value.as < std::shared_ptr<ExpressionList> > ();}
#line 1197 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"
    break;


#line 1201 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -42;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       1,    10,    26,     3,   -42,     4,    12,   -42,    75,    -9,
     -10,   -11,    -7,   -42,   -42,    -9,   -42,   -42,    -9,    -9,
     -42,    -9,   -42,   -42,     8,    18,    27,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   319,   -42,   395,    39,    -1,    32,
     -42,   -15,   114,   413,   -42,   431,     0,     2,    -9,    -9,
      -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,
      -9,    -9,   -42,   -42,    -9,    34,    -2,   -42,   -42,   -42,
     -42,   -42,   338,   -15,   -15,   -42,   -42,   -42,   485,   467,
     490,   490,    -8,    -8,    -8,    -8,   152,    29,   301,    -2,
     -42,   -42,   -42,    51,   190,   -18,    -3,   -42,   -42,   -42,
      -9,    -9,   -14,    -9,    30,    35,    -9,    36,   228,   449,
     449,    -9,   -42,   357,   -21,   -42,   449,   -42,   -42,   376,
     -42,   -42,   -42,   -42,   266,   -42
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     0,     0,     3,     0,     0,
       0,     0,     0,     7,     8,     0,     3,     2,     0,     0,
       6,     0,    35,    34,     0,     0,    36,    33,     4,     9,
      13,    10,    23,    22,     0,    36,     0,     0,     0,     0,
      16,    39,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     3,     0,     0,     0,     5,    38,     3,
      53,    53,     0,    52,    51,    48,    49,    50,    46,    47,
      42,    43,    45,    44,    40,    41,     0,     0,    29,     0,
      30,    31,    32,     0,     0,     0,     0,    11,    14,     3,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    27,
      28,     0,    25,     0,     0,    17,    54,    18,    15,     0,
      26,     3,    20,    24,     0,    21
  };

  const signed char
  parser::yypgoto_[] =
  {
     -42,   -42,   -16,   -42,   -42,   -41,   -42,   -42,   -42,   -42,
     -13,     6,     7
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     8,    28,    29,    30,    31,    32,    33,    87,
      93,    34,    95
  };

  const signed char
  parser::yytable_[] =
  {
      42,    38,   121,   111,     1,    51,    52,    53,   105,    15,
      49,    50,    51,    52,    53,    36,    18,    21,    19,   106,
       3,    41,   112,   107,    43,    44,     4,    45,     5,    40,
       6,    22,    23,    46,   106,     7,    39,    37,    35,    27,
      90,    91,    92,    47,    48,    64,    65,    86,    66,    70,
      89,    71,    99,    94,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,   103,   114,
      88,   115,   117,   122,     0,     0,   102,     0,    96,     9,
      10,     0,     0,   108,     0,     0,    11,     0,    12,    13,
      14,     0,     0,    15,     0,     0,     0,     0,    16,    17,
      18,     0,    19,     0,     0,   124,   109,   110,     0,   113,
       0,    20,   116,    21,     0,    22,    23,   119,     9,    10,
      24,    25,    26,    27,     0,    11,     0,    12,    13,    14,
       0,     0,    15,     0,     0,     0,     0,    16,    67,    18,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,    21,     0,    22,    23,     9,    10,     0,    24,
      25,    26,    27,    11,     0,    12,    13,    14,     0,     0,
      15,     0,     0,     0,     0,    16,    98,    18,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
      21,     0,    22,    23,     9,    10,     0,    24,    25,    26,
      27,    11,     0,    12,    13,    14,     0,     0,    15,     0,
       0,     0,     0,    16,   104,    18,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,    21,     0,
      22,    23,     9,    10,     0,    24,    25,    26,    27,    11,
       0,    12,    13,    14,     0,     0,    15,     0,     0,     0,
       0,    16,   118,    18,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,    21,     0,    22,    23,
       9,    10,     0,    24,    25,    26,    27,    11,     0,    12,
      13,    14,     0,     0,    15,     0,     0,     0,     0,    16,
     125,    18,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,    21,     0,    22,    23,   100,   101,
       0,    24,    25,    26,    27,     0,     0,     0,     0,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    97,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,    61,   120,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,    54,    55,    56,    57,    58,    59,
      60,    61,   123,    49,    50,    51,    52,    53,    63,     0,
       0,     0,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    49,    50,    51,    52,    53,     0,     0,     0,    68,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    49,
      50,    51,    52,    53,    69,     0,     0,     0,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,    54,     0,    56,    57,    58,
      59,    60,    61,    49,    50,    51,    52,    53,    49,    50,
      51,    52,    53,     0,     0,    56,    57,    58,    59,    60,
      61,     0,    58,    59,    60,    61
  };

  const signed char
  parser::yycheck_[] =
  {
      16,    12,    23,    17,     3,    20,    21,    22,    26,    18,
      18,    19,    20,    21,    22,     9,    25,    38,    27,    37,
      10,    15,    36,    26,    18,    19,     0,    21,    25,    36,
      26,    40,    41,    25,    37,    23,    47,    47,    47,    48,
      42,    43,    44,    25,    17,     6,    47,    63,    16,    49,
      16,    49,    23,    69,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    17,    39,
      64,    36,    36,   114,    -1,    -1,    89,    -1,    71,     4,
       5,    -1,    -1,    99,    -1,    -1,    11,    -1,    13,    14,
      15,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,    24,
      25,    -1,    27,    -1,    -1,   121,   100,   101,    -1,   103,
      -1,    36,   106,    38,    -1,    40,    41,   111,     4,     5,
      45,    46,    47,    48,    -1,    11,    -1,    13,    14,    15,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,    -1,    40,    41,     4,     5,    -1,    45,
      46,    47,    48,    11,    -1,    13,    14,    15,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    -1,    40,    41,     4,     5,    -1,    45,    46,    47,
      48,    11,    -1,    13,    14,    15,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    -1,
      40,    41,     4,     5,    -1,    45,    46,    47,    48,    11,
      -1,    13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    23,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    40,    41,
       4,     5,    -1,    45,    46,    47,    48,    11,    -1,    13,
      14,    15,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    38,    -1,    40,    41,     7,     8,
      -1,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    18,    19,    20,    21,    22,    -1,    -1,    -1,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,    18,    19,    20,    21,    22,    18,    19,
      20,    21,    22,    -1,    -1,    30,    31,    32,    33,    34,
      35,    -1,    32,    33,    34,    35
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    51,    10,     0,    25,    26,    23,    52,     4,
       5,    11,    13,    14,    15,    18,    23,    24,    25,    27,
      36,    38,    40,    41,    45,    46,    47,    48,    53,    54,
      55,    56,    57,    58,    61,    47,    61,    47,    12,    47,
      36,    61,    52,    61,    61,    61,    25,    25,    17,    18,
      19,    20,    21,    22,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    23,     6,    47,    16,    24,    26,    23,
      49,    49,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    52,    59,    61,    16,
      42,    43,    44,    60,    52,    62,    62,    36,    24,    23,
       7,     8,    60,    17,    24,    26,    37,    26,    52,    61,
      61,    17,    36,    61,    39,    36,    61,    36,    24,    61,
      36,    23,    55,    36,    52,    24
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    50,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    56,    56,    57,    57,    58,    59,    59,    59,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     7,     0,     2,     3,     1,     1,     1,     1,
       1,     4,     2,     1,     5,     7,     2,     6,     6,     5,
       7,     9,     1,     1,     8,     6,     7,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     0,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"fn\"", "\"while\"",
  "\"for\"", "\"in\"", "\"..\"", "\"..=\"", "\"\\\"\"", "\"main\"",
  "\"let\"", "\"mut\"", "\"return\"", "\"break\"", "\"continue\"", "\":\"",
  "\"=\"", "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"%\"", "\"{\"", "\"}\"",
  "\"(\"", "\")\"", "\"!\"", "\"&&\"", "\"||\"", "\"==\"", "\"!=\"",
  "\">\"", "\">=\"", "\"<\"", "\"<=\"", "\";\"", "\",\"", "\"if\"",
  "\"else\"", "\"true\"", "\"false\"", "\"i32\"", "\"String\"", "\"bool\"",
  "\"print!\"", "\"println!\"", "\"identifier\"", "\"number\"",
  "\"string_literal\"", "$accept", "program", "statements", "statement",
  "print_statement", "if_statement", "let_statement", "mut_let_statement",
  "const_let_statement", "iterator", "type", "expression",
  "expression_list", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   184,   184,   190,   191,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   208,   209,   212,
     213,   214,   217,   218,   221,   222,   225,   228,   229,   230,
     233,   234,   235,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   260,   261
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1827 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.cpp"

#line 272 "/Users/user/Documents/Физтех/3 семестр/FormalLangs/Mini-Fortran-Interpreter/parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
