#include <iostream>
#include <string>
#include <vector>

using namespace std;

//求两个大数的乘积（两数均为正数）
string GetProductOfTwoBigNum(string strNumLeft, string strNumRight)
{
	//使用小学所学方法，计算两个大数乘积

	if (strNumRight.empty() && strNumRight.empty())
	{
		return string("0");
	}

	//转换为数字
	for (string::size_type i = 0; i < strNumLeft.size(); ++i)
	{
		strNumLeft[i] -= '0';
	}
	for (string::size_type i = 0; i < strNumRight.size(); ++i)
	{
		strNumRight[i] -= '0';
	}


	string::size_type nMaxBits = strNumLeft.size() + strNumRight.size() + 1;//最大位数，多增加一位，便于编码
	string strProduct(nMaxBits, NULL);//保存每步乘积累加之和
	char szTemp = NULL;//每位乘积，辅助变量
	char szCarrayTemp = NULL;//进位信息

	for (int i = strNumRight.size() - 1; i >= 0; --i)
	{
		string strProductStep(nMaxBits, NULL);//保存每步之和
		int k = strNumRight.size() - i - 1;
		for (int j = strNumLeft.size() - 1; j >= 0; --j)
		{
			szTemp = (strNumRight[i] * strNumLeft[j] + strProductStep[k]) % 10;
			szCarrayTemp = (strNumRight[i] * strNumLeft[j] + strProductStep[k]) / 10;

			strProductStep[k] = szTemp;
			strProductStep[++k] += szCarrayTemp;
		}

		//将这一步结果累加strProduct中
		for (string::size_type m = 0; m < nMaxBits - 1; ++m)
		{
			szTemp = (strProductStep[m] + strProduct[m]) % 10;
			szCarrayTemp = (strProductStep[m] + strProduct[m]) / 10;

			strProduct[m] = szTemp;
			strProduct[m + 1] += szCarrayTemp;
		}
	}

	//返回遍历strProduct，从而取出计算的结果
	string strResult;
	int k = nMaxBits - 1;
	while (k >= 0 && strProduct[k] == NULL)
	{
		--k;
	}
	for (; k >= 0; --k)
	{
		strResult.push_back(strProduct[k] + '0');//转换为字符
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
	//计算小数位有效位数
	int nSignificantCount = 0;
	//查找小数点
	string::size_type nDotPos = strBigNum.find('.');
	if (nDotPos != string::npos)
	{
		//有小数点，计算小数有效位
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

		//去除小数点后的非有效数字，即0
		strBigNum = strBigNum.substr(0, nCurPos + 1);
	}
	nSignificantCount *= nPower;


	//去除小数点前的非有效数字，即0
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

	//去除小数点
	nDotPos = strBigNum.find('.');
	if (nDotPos != string::npos)
	{
		strBigNum.erase(nDotPos, 1);
	}


	//迭代计算大数的幂
	string strResult("1");
	while (nPower > 0)
	{
		strResult = GetProductOfTwoBigNum(strResult, strBigNum);
		--nPower;
	}

	//插入小数点
	if (strResult.size() < nSignificantCount)
	{
		//在前面补0
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
