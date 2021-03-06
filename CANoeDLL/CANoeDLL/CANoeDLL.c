// CANoeDLL.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"


#include "CANoeDLL.h"

int Packlen = 0x200;

U8 Ascii2Hex(char cha)
{
	U8 temp;
	if (cha >= 0x30 && cha <= 0x39)
	{
		temp = cha - 0x30;
	}
	else if (cha >= 'A'&&cha <= 'F')
	{
		temp = cha - 'A' + 10;
	}
	else if (cha >= 'a'&& cha <= 'f')
	{
		temp = cha - 'a' + 10;
	}
	else
	{
		temp = 255;
		write("error occured !");
	}
	return temp;
}

void DataTransfer(U8 InputData[], U8 OutputData[], U32 StartAdrr[], U32 TransferDataLen[])
	{
		U32 i = 0, index_point = 0;
		int offset;
		int flow = 0;
		int j;
		U32 InternalAddrr;
		U8 InternalLen;
		U8 InternalCheckSum;

		for (i = 0; i < sizeof(OutputData); i++)
		{
			OutputData[i] = 0xFF;
		}
		for (i = 0; i < sizeof(InputData); i++)
		{
			if (i == (sizeof(InputData) - 1))
			{
				//printf("Sick hex! %ld", i);
			}
			if ((InputData[i] == 'S') && (InputData[i + 1] == '0'))/*Data Start!*/
			{
				flow = 1;
				i = sizeof(InputData) - 1;
			}
		}
		if (flow == 1)
		{
			for (i = 0; i < sizeof(InputData); i++)
			{
				if ((InputData[i] == 'S') && (InputData[i + 1] == '2'))/*Adrress Start!*/
				{
					flow = 0;
					for (j = 0; j < 6; j++)
					{
						StartAdrr[0] = StartAdrr[0] << 4;
						StartAdrr[0] |= Ascii2Hex(InputData[i + 4 + j]);
					}
					i = sizeof(InputData) - 1;
				}
			}

			for (i = 0; i < sizeof(InputData); i++)
			{
				if ((InputData[i] == 'S') && (InputData[i + 1] == '3'))/*Adrress Start!*/
				{
					flow = 0;
					for (j = 0; j < 8; j++)
					{
						StartAdrr[0] = StartAdrr[0] << 4;
						StartAdrr[0] |= Ascii2Hex(InputData[i + 4 + j]);
					}
					i = sizeof(InputData) - 1;
				}
			}
		}

		for (i = 0; i < sizeof(InputData); i++)
		{
			InternalLen = 0;
			InternalAddrr = 0;
			InternalCheckSum = 0;
			if ((InputData[i] == 0x0A) && (InputData[i + 1] == 'S') && (InputData[i + 2] == '2'))
			{

				for (j = 0; j < 2; j++)
				{
					InternalLen = InternalLen << 4;
					InternalLen |= Ascii2Hex(InputData[i + 3 + j]);
				}
				for (j = 0; j < 6; j++)
				{
					InternalAddrr = InternalAddrr << 4;
					InternalAddrr |= Ascii2Hex(InputData[i + 5 + j]);
				}
				for (j = 0; j < 2; j++)
				{
					InternalCheckSum = InternalCheckSum << 4;
					InternalCheckSum |= Ascii2Hex(InputData[i + 2 * InternalLen + 3 + j]);
				}

				for (j = 0; j < (InternalLen - 4) * 2; j++)
				{
					OutputData[InternalAddrr - StartAdrr[0] + j / 2] = OutputData[InternalAddrr - StartAdrr[0] + j / 2] << 4;
					OutputData[InternalAddrr - StartAdrr[0] + j / 2] |= Ascii2Hex(InputData[i + 11 + j]);
					TransferDataLen[0] = InternalAddrr - StartAdrr[0] + j / 2;
				}
			}
			if ((InputData[i] == 0x0A) && (InputData[i + 1] == 'S') && (InputData[i + 2] == '3'))
			{
				for (j = 0; j < 2; j++)
				{
					InternalLen = InternalLen << 4;
					InternalLen |= Ascii2Hex(InputData[i + 3 + j]);
				}

				for (j = 0; j < 8; j++)
				{
					InternalAddrr = InternalAddrr << 4;
					InternalAddrr |= Ascii2Hex(InputData[i + 5 + j]);
				}

				for (j = 0; j < 2; j++)
				{
					InternalCheckSum = InternalCheckSum << 4;
					InternalCheckSum |= Ascii2Hex(InputData[i + 2 * InternalLen + 3 + j]);
				}

				for (j = 0; j < (InternalLen - 5) * 2; j++)
				{
					OutputData[InternalAddrr - StartAdrr[0] + j / 2] = OutputData[InternalAddrr - StartAdrr[0] + j / 2] << 4;
					OutputData[InternalAddrr - StartAdrr[0] + j / 2] |= Ascii2Hex(InputData[i + 13 + j]);
					TransferDataLen[0] = InternalAddrr - StartAdrr[0] + j / 2;
				}
			}
			if ((InputData[i] == 0x0A) && (InputData[i + 1] == 'S') && (InputData[i + 2] == '8'))
			{
				i = sizeof(InputData) - 1;
			}
			if ((InputData[i] == 0x0A) && (InputData[i + 1] == 'S') && (InputData[i + 2] == '7'))
			{
				i = sizeof(InputData) - 1;
			}
		}
		if ((TransferDataLen[0] % Packlen) != 0)
		{
			U32 DataLenSave;
			DataLenSave = TransferDataLen[0];
			//write("TransferDataLen region is %d",TransferDataLen[0]);
			// write("TransferDataLen data mod is %d",(Packlen-(TransferDataLen[0]%Packlen)));
			TransferDataLen[0] += (Packlen - (TransferDataLen[0] % Packlen));
			//write("TransferDataLen1 is %d",TransferDataLen[0]);

			for (i = DataLenSave + 1; i < TransferDataLen[0]; i++)
			{
				OutputData[i] = 0xFF;
			}
		}
	}

