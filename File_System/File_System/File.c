#include "Common.h"

status_t editFile()
{
	int iText = 0;//перед каким индексом стоит курсор
	int iEdit = 0;
	char* buf = NULL;
	if (cur->data)
	{
		while (cur->data[iText])//копирование текстового файла в буфер
		{
			char* values = (char*)realloc(buf, iText + 10);
			if (!values)
			{
				printf("ERROR: memory allocation problem.\n");
				return FAIL;
			}
			buf = values;
			if (iText == 0)
				strncpy(buf, cur->data[iText], 9);
			else
				strncat(buf, cur->data[iText], 9);
			iText += 9;
			buf[iText] = '\0';
		}
	}
	

	int curLen = iText;
	char code = '0';
    do
	{
		code = _getch();
		switch (code)
		{
		case CODE_ARROW:
			code = _getch();
			if (code == CODE_LEFT)//смещение курсора влево
			{
				if(iText>0)
				   iText--;
			}
				
			if (code == CODE_RIGHT)//смещение курсора вправо
				if (iText<curLen)
				   iText++;
			break;

		case CODE_SAVE://сохранение и выход из edit
			free(cur->data);
			cur->data = buf;
			printf("The file is successfuly saved.\n");
			return SUCCESS;

		case CODE_DELETE://удаление символа
			if (iText > 0)
			{
				iText--;
				for (iEdit = iText; iEdit < curLen - 1; iEdit++)
				   buf[iEdit] = buf[iEdit + 1];
				 curLen--;
				 buf[curLen] = '\0';
			}
			break;

		default://вставка символа
			curLen++;
			char* valuesAdd = (char*)realloc(buf, curLen+1);
			buf = valuesAdd;
			buf[curLen] = '\0';
			for (iEdit = curLen - 1; iEdit > iText; iEdit--)
				buf[iEdit] = buf[iEdit-1];
			buf[iText] = code;
			iText++;	
			break;
		}		

		system("cls");
		for (iEdit = 0; iEdit < curLen; iEdit++)
			printf("%c", buf[iEdit]);
		printf("\n");
		printf("The cursor is before a symbol with index %i\n", iText);
	} while (code != CODE_SAVE);
	return SUCCESS;
}