#ifndef _H_SCRIPT_PARSER
#define _H_SCRIPT_PARSER

#include <stdarg.h>
#include <stdio.h>

#include "hotpot/hp_platform.h"
#include "hot_vm.h"
#include "hotscript/hotlex.h"

typedef struct _SP_NODE
{
	int token;
	HPVar var;

	//���¼��������¼��Ҫ���ݴ�����ָ��	
	hpuint32 call_field_begin_index;
	hpuint32 field_begin_index;
	hpuint32 vector_begin_index;
	hpuint32 vector_item_begin_index;
	hpuint32 echo_field_index;	
}SP_NODE;


typedef struct tagSCRIPT_PARSER SCRIPT_PARSER;
struct tagSCRIPT_PARSER
{
	SCANNER_STACK scanner_stack;

	hpint32 result;
	HotOpArr hotoparr;


	HPAbstractReader *reader;
	HotVM hotvm;
};

hpint32 script_parser(SCRIPT_PARSER *self, const char* file_name, HPAbstractReader *reader, 
					  void *user_data, vm_user_putc uputc);

hpint32 script_parser_str(SCRIPT_PARSER *self, char* script, char *script_limit, 
						  HPAbstractReader *reader, void *user_data, vm_user_putc uputc);


hpint32 hotscript_do_text(SCRIPT_PARSER *self, const YYLTYPE *yylloc, const SP_NODE *text);

hpint32 hotscript_do_literal(SCRIPT_PARSER *self, const YYLTYPE *yylloc, const SP_NODE *text);

hpint32 hotscript_do_field_begin(SCRIPT_PARSER *self, const YYLTYPE *yylloc, SP_NODE *identifier);

hpint32 hotscript_do_field_end(SCRIPT_PARSER *self, const YYLTYPE *yylloc, SP_NODE *identifier);

hpint32 hotscript_do_vector_begin(SCRIPT_PARSER *self, const YYLTYPE *yylloc, SP_NODE *identifier);

hpint32 hotscript_do_vector_end(SCRIPT_PARSER *self, const YYLTYPE *yylloc, SP_NODE *identifier);

hpint32 hotscript_do_field(SCRIPT_PARSER *self, const YYLTYPE *yylloc, SP_NODE *current);

hpint32 hotscript_do_echo_field(SCRIPT_PARSER *self, const YYLTYPE *yylloc);

#endif//_H_SCRIPT_PARSER
