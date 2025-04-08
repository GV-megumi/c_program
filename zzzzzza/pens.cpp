#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 定义文具基类
class Stationery
{
public:
	// 构造函数，初始化文具的名称和价格
	Stationery(const string& name, double price) : name(name), price(price) {}
	
	// 虚函数，计算总价格
	virtual double calculateTotalPrice(int quantity)
	{
		return price * quantity;
	}
	
	// 纯虚函数，计算折扣
	virtual double calculateDiscount(int quantity) = 0;
	
	// 虚函数，显示文具信息
	virtual void display(int quantity)
	{
		// 计算总金额和折扣金额
		double totalAmount = calculateTotalPrice(quantity);
		double discountAmount = calculateDiscount(quantity);
		
		// 显示文具信息
		cout << "品名: " << name << " 数量: " << quantity << " 单价: " << price
		<< " 总金额: " << totalAmount << " 折扣金额: " << discountAmount << endl;
	}
	
protected:
	string name;    // 文具名称
	double price;   // 文具价格
};

// 圆珠笔类，继承自文具基类
class BallpointPen : public Stationery
{
public:
	// 构造函数，初始化圆珠笔的名称、价格和颜色
	BallpointPen(const string& name, double price, char color) : Stationery(name, price), color(color) {}
	
	// 重写基类的计算总价格函数
	double calculateTotalPrice(int quantity) 
	{
		// 计算商品总价
		double totalPrice = price * quantity; 
		// 商品总价等于单价乘以数量
		
		// 计算折扣金额
		double discountAmount = calculateDiscount(quantity); 
		// 调用 calculateDiscount 函数，根据商品数量计算折扣金额
		
		// 返回最终支付金额
		return totalPrice - discountAmount; 
		// 返回商品总价减去折扣金额，得到最终支付金额
	}
	
	// 重写基类的计算折扣函数
	double calculateDiscount(int quantity)
	{
		// 如果购买数量大于等于10，享受5%的折扣
		return quantity >= 10 ? price * quantity * 0.05 : 0;
	}
	
	// 重写基类的显示函数
	void display(int quantity) 
	{
		// 调用基类的显示函数
		Stationery::display(quantity);
		
		// 显示圆珠笔的颜色
		cout << "颜色: " << color << endl;
	}
	
private:
	char color;    // 圆珠笔颜色
};


// 练习本类，继承自文具基类
class ExerciseBook : public Stationery
{
public:
	// 构造函数，初始化练习本的名称、价格和页数
	ExerciseBook(const string& name, double price, int pageCount) : Stationery(name, price), pageCount(pageCount) {}
	
	// 重写基类的计算总价格函数
	double calculateTotalPrice(int quantity) 
	{
		// 计算商品总价
		double totalPrice = price * quantity; 
		// 商品总价等于单价乘以数量
		
		// 计算折扣金额
		double discountAmount = calculateDiscount(quantity); 
		// 调用 calculateDiscount 函数，根据商品数量计算折扣金额
		
		// 返回最终支付金额
		return totalPrice - discountAmount; 
		// 返回商品总价减去折扣金额，得到最终支付金额
		
	}
	
	// 重写基类的计算折扣函数
	double calculateDiscount(int quantity) 
	{
		// 如果购买数量大于等于10，享受7%的折扣
		return quantity >= 10 ? price * quantity * 0.07 : 0;
	}
	
	// 重写基类的显示函数
	void display(int quantity)
	{
		// 调用基类的显示函数
		Stationery::display(quantity);
		
		// 显示练习本的页数
		cout << "页数: " << pageCount << endl;
	}
	
private:
	int pageCount;    // 练习本的页数
};

// 尺子类，继承自文具基类
class Ruler : public Stationery
{
public:
	// 构造函数，初始化尺子的名称、价格和刻度长度
	Ruler(const string& name, double price, double scaleLength) : Stationery(name, price), scaleLength(scaleLength) {}
	
	// 重写基类的计算总价格函数
	double calculateTotalPrice(int quantity) 
	{
		// 计算商品总价
		double totalPrice = price * quantity; 
		// 商品总价等于单价乘以数量
		
		// 计算折扣金额
		double discountAmount = calculateDiscount(quantity); 
		// 调用 calculateDiscount 函数，根据商品数量计算折扣金额
		
		// 返回最终支付金额
		return totalPrice - discountAmount; 
		// 返回商品总价减去折扣金额，得到最终支付金额
		
	}
	
	// 重写基类的计算折扣函数
	double calculateDiscount(int quantity) 
	{
		// 如果购买数量大于等于10，享受3%的折扣
		return quantity >= 10 ? price * quantity * 0.03 : 0;
	}
	
	// 重写基类的显示函数
	void display(int quantity)  
	{
		// 调用基类的显示函数
		Stationery::display(quantity);
		
		// 显示尺子的刻度长度
		cout << "刻度长度: " << scaleLength << endl;
	}
	
private:
	double scaleLength;    // 尺子的刻度长度
};

int main()
{
	// 定义存储文具对象指针的向量
	vector<Stationery*> items;
	
	// 定义圆珠笔、练习本和尺子的数量、单价和其他相关变量
	int quantityPen, quantityBook, quantityRuler;    // 分别存储圆珠笔、练习本和尺子的数量
	double pricePen, priceBook, priceRuler;          // 分别存储圆珠笔、练习本和尺子的单价
	char colorPen;                                   // 存储圆珠笔的颜色
	int pageCount;                                   // 存储练习本的页数
	double scaleLength;                              // 存储尺子的长度

	
	// 用户输入圆珠笔的数量、单价和颜色，创建对应的圆珠笔对象，并将其指针加入向量
	cout << "请输入圆珠笔数量、单价和颜色（例如：10 2 B）: ";
	cin >> quantityPen >> pricePen >> colorPen;
	items.push_back(new BallpointPen("圆珠笔", pricePen, colorPen));
	
	// 用户输入练习本的数量、单价和页数，创建对应的练习本对象，并将其指针加入向量
	cout << "请输入练习本数量、单价和页数（例如：15 3 100）: ";
	cin >> quantityBook >> priceBook >> pageCount;
	items.push_back(new ExerciseBook("练习本", priceBook, pageCount));
	
	// 用户输入尺子的数量、单价和刻度长度，创建对应的尺子对象，并将其指针加入向量
	cout << "请输入尺子数量、单价和刻度长度（例如：9 6 15.0）: ";
	cin >> quantityRuler >> priceRuler >> scaleLength;
	items.push_back(new Ruler("尺子", priceRuler, scaleLength));
	
	// 初始化总金额、总折扣、总数量以及是否有商品享受折扣的标志
	double totalAmountBeforeDiscount = 0.0;  // 存储折扣前的总金额
	double totalAmount = 0.0;                // 存储折扣后的总金额
	double totalDiscount = 0.0;              // 存储总折扣金额
	int totalQuantity = 0;                   // 存储总数量
	bool isAnyItemDiscounted = false;        // 用于检查是否有任何商品享受单品折扣的标志
	// 遍历文具对象向量，计算总金额、总折扣和总数量
	for (auto item : items)
	{
		int quantity = 0;
		
		// 根据对象类型确定对应的数量变量
		if (dynamic_cast<BallpointPen*>(item))
		{
			quantity = quantityPen; // 如果当前商品是钢笔类型，将其数量赋值给 quantity
		}
		else if (dynamic_cast<ExerciseBook*>(item))
		{
			quantity = quantityBook; // 如果当前商品是练习本类型，将其数量赋值给 quantity
		}
		else if (dynamic_cast<Ruler*>(item))
		{
			quantity = quantityRuler; // 如果当前商品是尺子类型，将其数量赋值给 quantity
		}
		
		
		// 计算每个商品的总金额
		totalAmountBeforeDiscount += item->calculateTotalPrice(quantity);
		
		// 计算每个商品的折扣
		double itemDiscount = item->calculateDiscount(quantity);
		
		// 如果有折扣，更新折扣总额和折扣标志
		if (itemDiscount > 0)
		{
			isAnyItemDiscounted = true; // 检查是否有任何商品享受了单品折扣
		}
		totalDiscount += itemDiscount;  // 累加每个商品的折扣到总折扣
		totalQuantity += quantity;  // 累加每个商品的数量到总数量
	}
	
	
	// 计算总金额时，不包括单价的折扣
	totalAmountBeforeDiscount = totalAmountBeforeDiscount;
	
	// 仅在没有商品享受单品折扣时应用总额折扣
	if (!isAnyItemDiscounted && totalQuantity >= 10)
	{
		// 计算总额折扣的额外折扣金额
		double additionalDiscount = totalAmountBeforeDiscount * 0.1;
		// 应用总额折扣后的总金额
		totalAmount = totalAmountBeforeDiscount - additionalDiscount;
		// 更新总折扣金额
		totalDiscount += additionalDiscount;
	}
	else
	{
		// 若有商品享受了单品折扣或商品数量不足10个，则总金额不变
		totalAmount = totalAmountBeforeDiscount;
	}
	
	// 显示每个商品的详情
	for (auto item : items)
	{
		int quantity = 0;
		// 检查每种商品类型的数量并显示其详情
		if (dynamic_cast<BallpointPen*>(item))
		{
			quantity = quantityPen; // 记录钢笔的数量
		}
		else if (dynamic_cast<ExerciseBook*>(item))
		{
			quantity = quantityBook; // 记录练习本的数量
		}
		else if (dynamic_cast<Ruler*>(item))
		{
			quantity = quantityRuler; // 记录尺子的数量
		}
		item->display(quantity); // 显示当前商品的详情
	}
	
	// 显示总金额和总折扣
	cout << "总金额: " << totalAmount << endl; // 显示计算后的总金额
	cout << "总折扣金额: " << totalDiscount << endl; // 显示总折扣金额
	
	// 清理动态分配的内存
	for (auto item : items)
	{
		delete item; // 删除每个商品对象以释放内存
	}
	
	return 0; // 返回程序结束状态
}