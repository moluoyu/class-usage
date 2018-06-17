#include<iostream>
#include <conio.h>
#include<fstream>
#include<string>
#include <vector>
using namespace std;

namespace chili {
	void strrev(char *p1)
	{
		char *pr = p1;
		for (; *pr != 0; pr++)
			pr--;

		for (; p1 < pr; p1++, pr--)
		{
			const char temp = *p1;
			*p1 = *pr;
			*pr = temp;
		}
	}


	void printFixed(const char * s, int w)
	{
		int n = 0;
		for (; *s != 0; s++)
		{
			n++;
			_putch(*s);
		}
		for (; n < w; n++)
		{
			_putch(' ');

		}

	}
	void print(const char * s)
	{
		for (; *s != 0; s++)
		{
			_putch(*s);
		}
		cout << endl;
	}
	void strcpy(const char* pSrc, char *pDst)
	{
		for (; *pSrc != 0; pSrc++,pDst++)
		{
			*pDst = *pSrc;

		}
		*pDst = 0;
	}
	void read(char * buf, int maxSize)
	{
		const char * const pEnd = buf + maxSize;
		for (char c = _getch(); c != 13 && (buf + 1 < pEnd); c = _getch(), c++)
		{
			_putch(c);
			*buf = c;
		}
		*buf = 0;
	}
	void int2str(int val, char * buf, int size)
	{
		char * const pStart = buf;
		char * const pEnd = buf + size;
		for (; val > 0 && (buf + 1 < pEnd); val /= 10, buf++)
		{
			*buf = '0'+ val % 10;
		}
		*buf = 0;
		strrev(pStart);
	}
	

	class Database
	{
	private:
		class Entry
		{
		public:
			Entry() = default;
			Entry(const char * name, int value)
				:value(value)
			{//感觉有问题？？
				strcpy(name, this->name);

			}
			void Print() const
			{
				printFixed(name, nameBufferSize - 1);
				_putch('|');
				for (int n = 0; n < value; n++)
				{
					_putch('=');
				}
				_putch('\n');
			}
			void Serialize(ofstream & out) const
			{
				out.write(name,sizeof(name) );
				out.write(reinterpret_cast<const char *>(&value), sizeof(value));
			
			}
			void Deserialize(ifstream & in)
			{
				in.read(name, sizeof(name));
				in.read(reinterpret_cast< char *>(&value), sizeof(value));

			}
		private:
			static constexpr int  nameBufferSize = 16;
			char name[nameBufferSize];
			int value;


		};

	public:
		void Load(const char *  filename)
		{
			ifstream in(filename, ios::binary);
			in.read(reinterpret_cast< char *>(&curNumberEntries), sizeof(curNumberEntries));
			for (int i = 0; i < curNumberEntries; i++)
			{
				entries[i].Deserialize(in);
			}
		}
		void Save(const char * filename) const 
		{
			ofstream out(filename, ios::binary);
			out.write(reinterpret_cast<const char *>(&curNumberEntries), sizeof(curNumberEntries));
			for (int i = 0; i < curNumberEntries; i++)
			{
				entries[i].Serialize(out);
			}
			
		}
		void Print()const
		{
			entries[curNumberEntries].Print();
		}
		void Add(const char * name, int val)
		{
			if (curNumberEntries < maxNumberEntries)
			{
				entries[curNumberEntries++] = { name,val };

			}

		}
	private:
		static constexpr int maxNumberEntries = 16;
		Entry entries[maxNumberEntries];
		int curNumberEntries = 0;
	


	};

	






}

void strcpy(const char * pSrc, char * pDst)
{
	for (; *pSrc != 0; pSrc++, pDst++)
	{
		*pDst = *pSrc;
	}
	*pDst = 0;


}




int main()
{
	chili::Database db;
	bool quitting = false;
	char buffer[256];
	do
	{
		chili::print("(l)oad (s)ave (a)dd (p)rint?");
		char reponse = _getch();
		switch (reponse)
		{
		case 'l':
			chili::print("\nEnter file name: ");
			chili::read(buffer, sizeof(buffer));
			break;
		default:
			break;
		}
	}

	
	while (!_kbhit());
	return 0;
}

/*

	int str2int(const char * s)
	{
	//scan to start point
	const char * p = s;
	for (; *p >= '0' && *p <= '9'; p++);//find the last char in the number ex:12345gxww
	p--;                              //p is pointer to  '5'
	int val = 0;
	int place = 1;
	//
	for (; p >= s; p--)
	{
	val += (*p - '0') * place;
	place *= 10;
	}
	if (*s >= '0' && *s <= '9')
	{
	return *s - '0';
	}
	return val;
	}





std::ifstream in("derp.txt");
	in.seekg(0, std::ios_base::beg);
	for(char c = in.get(); in.good();c= in.get())
	{
		_putch(c);		
	}
	if (in.bad())
	{
		std::cout << "bad up ";
	}
	else if (in.eof())
	{
		cout << "reached the end of file.";
	}
	else
	{
		std::cout << "Some kind of fail ?";
	}

	ofstream out("out.txt");
	for (char c = _getch(); c != 13; c = _getch())
	{
		out.put(c);
	}
	*/





