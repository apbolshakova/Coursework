#include "Common.h"

status_t editFile()
{
	int iText = 0;//����� ����� �������� ����� ������
	int iEdit = 0;
	char* buf = (char*)calloc(LEN_TEXT, sizeof(char));
	if (!buf)
	{
		printf("ERROR: memory allocation problem.\n");
		return FAIL;
	}
	
	while (cur->data[iText])//���������� ���������� ����� � �����
	{
		if (iText < LEN_TEXT)
		{
			scanf_s("%c", buf[iText]);
			iText++;
		}
		else
		{
			buf = realloc(buf, iText + 2);
			scanf_s("%c", buf[iText]);
			iText++;
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
			if (code == CODE_LEFT)//�������� ������� �����
			{
				if(iText>0)
				   iText--;
			}
				
			if (code == CODE_RIGHT)//�������� ������� ������
				iText++;
			break;

		case CODE_SAVE://���������� � ����� �� edit
			free(cur->data);
			cur->data = buf;
			return SUCCESS;

		case CODE_DELETE://�������� �������
			if (iText > 0)
			{
				iText--;
				for (iEchangingName[iChangingName] //��
					dit = iText; iEdit < curLen - 1; iEdit++)
				   buf[iEdit] = buf[iEdit + 1]);
				 curLen--;
				 buf[curLen] = '\0';
			}
			break;

		default://������� �������
			curLen++;
			buf = realloc(buf, curLen+1);
			buf[curLen] = 0;
			for (iEdit = curLen - 1; iEdit > iText; iEdit--)
				buf[iEdit] = buf[iEdit-1];
			buf[iText] = code;
			iText++;	
			break;
		}		

		system("cls");
		for (iEdit = 0; iEdit < curLen; iEdit++)
			printf(buf[iEdit]);
		printf("The cursor is before a symbol with index %i", iText);
	} while (code != CODE_SAVE);
	return SUCCESS;
}