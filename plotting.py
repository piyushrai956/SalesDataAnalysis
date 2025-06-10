import matplotlib.pyplot as plt

years = []
revenues = []
expenses = []

with open("D:\\MyFolder\\c++\\sem2pracfile\\SalesDataAnalysissem2project\\data.txt", "r") as file:
    for line in file:
        parts = line.strip().split()
        years.append(parts[0])
        revenues.append(int(parts[1]))
        expenses.append(int(parts[2]))

plt.figure(figsize=(10, 6))

plt.subplot(2, 1, 1)  #top subplot
plt.title("Yearly Sales Trend")
plt.ylabel("Revenue")

plt.plot(years, revenues, marker='o', color='blue', label='Revenue')
plt.grid()

plt.subplot(2, 1, 2)  #bottom subplot
plt.xlabel("Year")
plt.ylabel("Expenses")

plt.plot(years, expenses, marker='o', color='red', label='Expenses')
plt.grid()

plt.tight_layout()
plt.show()  #show both plots

plt.title("Firm's Data")  #bar chart
plt.ylabel("Revenues")
plt.xlabel("Years")
    
plt.bar(years, revenues, width = 0.5)
plt.grid()
plt.show()  #show bar chart

plt.tight_layout()