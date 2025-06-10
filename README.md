# Sales Data Analysis System

A simple C++ and Python-based project for recording, analyzing, and visualizing company sales data.

## Project Overview
This project allows users to:
- Input yearly sales data (revenue and expenses)
- Read and display saved data
- Search or delete data by year
- Visualize sales trends using graphs
- Analyze financial performance using metrics like profit and YoY growth

## Components
### 1. `mainproject.cpp`
- Core C++ program with menu-driven options.
- Handles:
  - Writing, reading, searching, and deleting sales data
  - Calls Python scripts for plotting and analysis using `system()` function

### 2. `data.txt`
- Text file that stores sales data in the format:
  ```
  year revenue expenses
  ```

### 3. `plotting.py`
- Generates:
  - Line plots of revenue and expenses
  - Bar chart of yearly revenues

### 4. `analysis.py`
- Computes:
  - Yearly profits
  - Year-over-Year (YoY) revenue and expense growth
  - Summary of total profit, loss years, and profitability

## Example Output (Analysis)
```
Total Revenue: 300000
Total Expenses: 210000
Total Profit: 90000
Number of Profitable Years: 3
Number of Loss Years: 0
Overall, the company is profitable.
```

## Dependencies
- C++ compiler (e.g., g++)
- Python 3
- `matplotlib` (`pip install matplotlib`)
