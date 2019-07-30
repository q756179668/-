#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�����������ĳ˻���������Ϊ������
string GetProductOfTwoBigNum(string strNumLeft, string strNumRight)
{
	//ʹ��Сѧ��ѧ�������������������˻�

	if (strNumRight.empty() && strNumRight.empty())
	{
		return string("0");
	}

	//ת��Ϊ����
	for (string::size_type i = 0; i < strNumLeft.size(); ++i)
	{
		strNumLeft[i] -= '0';
	}
	for (string::size_type i = 0; i < strNumRight.size(); ++i)
	{
		strNumRight[i] -= '0';
	}


	string::size_type nMaxBits = strNumLeft.size() + strNumRight.size() + 1;//���λ����������һλ�����ڱ���
	string strProduct(nMaxBits, NULL);//����ÿ���˻��ۼ�֮��
	char szTemp = NULL;//ÿλ�˻�����������
	char szCarrayTemp = NULL;//��λ��Ϣ

	for (int i = strNumRight.size() - 1; i >= 0; --i)
	{
		string strProductStep(nMaxBits, NULL);//����ÿ��֮��
		int k = strNumRight.size() - i - 1;
		for (int j = strNumLeft.size() - 1; j >= 0; --j)
		{
			szTemp = (strNumRight[i] * strNumLeft[j] + strProductStep[k]) % 10;
			szCarrayTemp = (strNumRight[i] * strNumLeft[j] + strProductStep[k]) / 10;

			strProductStep[k] = szTemp;
			strProductStep[++k] += szCarrayTemp;
		}

		//����һ������ۼ�strProduct��
		for (string::size_type m = 0; m < nMaxBits - 1; ++m)
		{
			szTemp = (strProductStep[m] + strProduct[m]) % 10;
			szCarrayTemp = (strProductStep[m] + strProduct[m]) / 10;

			strProduct[m] = szTemp;
			strProduct[m + 1] += szCarrayTemp;
		}
	}

	//���ر���strProduct���Ӷ�ȡ������Ľ��
	string strResult;
	int k = nMaxBits - 1;
	while (k >= 0 && strProduct[k] == NULL)
	{
		--k;
	}
	for (; k >= 0; --k)
	{
		strResult.push_back(strProduct[k] + '0');//ת��Ϊ�ַ�
	}

	if (strResult.empty())
	{
		strResult.push_back('0');
	}

	return strResult;
}


string GetExponentiationOfBigNum(string strBigNum, unsigned int nPower)
{
	if (strBigNum.empty())
	{
		return string("0");
	}

	if (nPower == 0)
	{
		return string("1");
	}

	//////////////////////////////////
	//����С��λ��Чλ��
	int nSignificantCount = 0;
	//����С����
	string::size_type nDotPos = strBigNum.find('.');
	if (nDotPos != string::npos)
	{
		//��С���㣬����С����Чλ
		string::size_type nCurPos = strBigNum.size() - 1;
		while (nCurPos > nDotPos)
		{
			if (strBigNum[nCurPos] != '0')
			{
				break;
			}
			--nCurPos;
		}
		nSignificantCount = nCurPos - nDotPos;

		//ȥ��С�����ķ���Ч���֣���0
		strBigNum = strBigNum.substr(0, nCurPos + 1);
	}
	nSignificantCount *= nPower;


	//ȥ��С����ǰ�ķ���Ч���֣���0
	nDotPos = strBigNum.find('.');
	if (nDotPos != string::npos)
	{
		string::size_type nCurPos = 0;
		while (nCurPos < nDotPos)
		{
			if (strBigNum[nCurPos] != '0')
			{
				break;
			}
			++nCurPos;
		}
		strBigNum = strBigNum.erase(0, nCurPos);
	}

	//ȥ��С����
	nDotPos = strBigNum.find('.');
	if (nDotPos != string::npos)
	{
		strBigNum.erase(nDotPos, 1);
	}


	//���������������
	string strResult("1");
	while (nPower > 0)
	{
		strResult = GetProductOfTwoBigNum(strResult, strBigNum);
		--nPower;
	}

	//����С����
	if (strResult.size() < nSignificantCount)
	{
		//��ǰ�油0
		strResult.insert(0, nSignificantCount - strResult.size(), '0');
	}
	if (nSignificantCount > 0)
	{
		strResult.insert(strResult.size() - nSignificantCount, 1, '.');
	}



	return strResult;
}


int main()
{

	string strNum;
	unsigned int nPower;
	while (cin >> strNum >> nPower)
	{
		cout << GetExponentiationOfBigNum(strNum, nPower) << endl;
	}

	return 0;
}
