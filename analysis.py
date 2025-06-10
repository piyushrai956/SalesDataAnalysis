import matplotlib.pyplot as plt

years = []
revenues = []
expenses = []
profits = []
yoyrevgrowth = []
yoyexpgrowth = []

with open("data.txt", "r") as file:
    for line in file:
        parts = line.strip().split()
        year = int(parts[0])
        revenue = int(parts[1])
        expense = int(parts[2])
        
        profit = revenue - expense
        profitmargin = (profit / revenue) * 100 if revenue != 0 else 0
        
        years.append(year)
        revenues.append(revenue)
        expenses.append(expense)
        profits.append(profit)

for i in range(1, len(years)):
    revgrowth = ((revenues[i] - revenues[i - 1]) / revenues[i - 1]) * 100 if revenues[i - 1] != 0 else 0
    expgrowth = ((expenses[i] - expenses[i - 1]) / expenses[i - 1]) * 100 if expenses[i - 1] != 0 else 0
    
    yoyrevgrowth.append(revgrowth)
    yoyexpgrowth.append(expgrowth)        

plt.figure(figsize=(10, 6))

plt.title("Yearly Profits Trend")
plt.plot(years, profits, marker='o', color='green', label='Profit')
plt.ylabel("Profit")
plt.xlabel("Year")
plt.grid()
plt.legend()

plt.show()  #show profit trend

plt.title("Year-over-Year (YoY) Growth")
plt.plot(years[1:], yoyrevgrowth, marker='o', color='blue', label='Revenue Growth (%)')
plt.plot(years[1:], yoyexpgrowth, marker='o', color='red', label='Expense Growth (%)')
plt.xlabel("Year")
plt.ylabel("Growth (%)")
plt.grid()
plt.legend()

plt.tight_layout()
plt.show()  #show YoY growth

totalrev = sum(revenues)
totalexp = sum(expenses)
totalprofit = sum(profits)
profitableyears = sum(1 for p in profits if p > 0)
lossyears = len(profits) - profitableyears

print("\n--- Insights on the Data ---")
print(f"Total Revenue: {totalrev}")
print(f"Total Expenses: {totalexp}")
print(f"Total Profit: {totalprofit}")
print(f"Number of Profitable Years: {profitableyears}")
print(f"Number of Loss Years: {lossyears}")

if totalprofit > 0:
    print("Overall, the company is profitable.")
else:
    print("Overall, the company is running at a loss.")
