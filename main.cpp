#include <iostream>
#include <iomanip>
#include <limits>

struct Data
{
  float TotalRainfall;
  int HighTemperature;
  int LowTemperature;
  float avgTemperature;
};

int main()
{
  Data details[12];
  float TotalRainfallYear = 0;
  int HighestTemperature = std::numeric_limits<int>::min();
  int LowestTemperature = std::numeric_limits<int>::max();
  float sumOfavgTemperatures = 0;

  // Collect weather data for each month
  for (int i = 0; i < 12; i++)
  {
    std::cout << "Month " << i + 1 << ":\n";

    // Collect total rainfall for the month
    std::cout << "        Total rainfall: ";
    std::cin >> details[i].TotalRainfall;
    TotalRainfallYear += details[i].TotalRainfall;

    // Collect low temperature for the month within the specified range
    int temperature;
    do
    {
      std::cout << "        Low temperature (Between -100 and 140): ";
      std::cin >> temperature;

      if (temperature < -100 || temperature > 140)
      {
        std::cout << "Invalid temperature. Please enter a value between -100 and 140.\n";
      }

    } while (temperature < -100 || temperature > 140);
    details[i].LowTemperature = temperature;

    // Update the lowest temperature for the year if necessary
    if (details[i].LowTemperature < LowestTemperature)
    {
      LowestTemperature = details[i].LowTemperature;
    }

    // Collect high temperature for the month within the specified range
    do
    {
      std::cout << "        High temperature (Between -100 and 140): ";
      std::cin >> temperature;

      if (temperature < -100 || temperature > 140)
      {
        std::cout << "Invalid temperature. Please enter a value between -100 and 140.\n";
      }

    } while (temperature < -100 || temperature > 140);
    details[i].HighTemperature = temperature;

    // Update the highest temperature for the year if necessary
    if (details[i].HighTemperature > HighestTemperature)
    {
      HighestTemperature = details[i].HighTemperature;
    }

    // Calculate the average temperature for the month
    details[i].avgTemperature = (details[i].HighTemperature + details[i].LowTemperature) / 2.0;
    sumOfavgTemperatures += details[i].avgTemperature;

    // Clear the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  // Calculate the average monthly rainfall and average temperature for the year
  float averageMonthlyRainfall = TotalRainfallYear / 12;
  float avgTemperature = sumOfavgTemperatures / 12;

  // Display the weather summary
  std::cout << "\nWeather Summary:\n";
  std::cout << "Total Rainfall for the Year: " << TotalRainfallYear << " mm\n";
  std::cout << "Average Monthly Rainfall: " << averageMonthlyRainfall << " mm\n";
  std::cout << "Highest Temperature for the Year: " << HighestTemperature << "°F\n";
  std::cout << "Lowest Temperature for the Year: " << LowestTemperature << "°F\n";
  std::cout << "Average of Monthly Average Temperatures: " << avgTemperature << "°F\n";

  system("pause>0");
}
