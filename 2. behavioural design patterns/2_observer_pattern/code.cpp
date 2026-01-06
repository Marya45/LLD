#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
using namespace std;

// ----------------------------
// Observer Interface
// MUST be defined before WeatherStation
// ----------------------------
class WeatherObserver {
public:
    virtual void update() = 0;
    virtual ~WeatherObserver() = default;
};

// ----------------------------
// Observable (Subject) Interface
// ----------------------------
class WeatherObservable {
public:
    virtual void addObserver(WeatherObserver* observer) = 0;
    virtual void removeObserver(WeatherObserver* observer) = 0;
    virtual void notifyObservers() = 0;

    virtual void setWeatherReadings(float temperature, float humidity, float pressure) = 0;

    virtual float getTemperature() const = 0;
    virtual float getHumidity() const = 0;
    virtual float getPressure() const = 0;

    virtual string toString() const = 0;

    virtual ~WeatherObservable() = default;
};

// ----------------------------
// Concrete Observable - WeatherStation
// ----------------------------
class WeatherStation : public WeatherObservable {
private:
    vector<WeatherObserver*> observers;
    float temperature{}, humidity{}, pressure{};

public:
    void addObserver(WeatherObserver* observer) override {
        observers.push_back(observer);
        cout << "[+] Observer registered: " << typeid(*observer).name() << endl;
    }

    void removeObserver(WeatherObserver* observer) override {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
        cout << "[-] Observer removed: " << typeid(*observer).name() << endl;
    }

    void notifyObservers() override {
        for (auto* observer : observers) {
            observer->update();
        }
    }

    void setWeatherReadings(float t, float h, float p) override {
        temperature = t;
        humidity = h;
        pressure = p;
        notifyObservers();
    }

    float getTemperature() const override { return temperature; }
    float getHumidity() const override { return humidity; }
    float getPressure() const override { return pressure; }

    string toString() const override {
        return "WeatherStation{ temperature=" + to_string(temperature) +
               ", humidity=" + to_string(humidity) +
               ", pressure=" + to_string(pressure) + " }";
    }
};

// ----------------------------
// Concrete Observer 1
// ----------------------------
class CurrentConditionsDisplay : public WeatherObserver {
private:
    WeatherObservable* weatherStation;

public:
    CurrentConditionsDisplay(WeatherObservable* station) {
        weatherStation = station;
        station->addObserver(this);
    }

    void update() override {
        cout << "Saving weather data..." << endl;
        display();
    }

    void display() {
        cout << "Current Weather Conditions: " 
             << weatherStation->toString()
             << endl;
    }
};

// ----------------------------
// Concrete Observer 2
// ----------------------------
class ForecastDisplay : public WeatherObserver {
private:
    WeatherObservable* weatherStation;

public:
    ForecastDisplay(WeatherObservable* station) {
        weatherStation = station;
        station->addObserver(this);
    }

    void update() override {
        cout << "Updating weather data to do some analytics: "
             << weatherStation->toString()
             << endl;
        display();
    }

    void display() {
        cout << "Forecast Details: Displaying information about Rain, "
             << "Temperature Trends, Significant Weather Events and other phenomena..."
             << endl;
    }
};

// ----------------------------
// Client Code
// ----------------------------
int main() {
    cout << "###### Observer Design Pattern ######" << endl;

    WeatherObservable* weatherStation = new WeatherStation();

    auto* currentDisplay = new CurrentConditionsDisplay(weatherStation);
    auto* forecastDisplay = new ForecastDisplay(weatherStation);

    cout << "\n===>>> Initial Weather Update" << endl;
    weatherStation->setWeatherReadings(80, 65, 30.4f);

    cout << "\n===>>> Second Weather Update" << endl;
    weatherStation->setWeatherReadings(82, 70, 29.2f);

    cout << "\n===>>> Removing Forecast Display" << endl;
    weatherStation->removeObserver(forecastDisplay);

    cout << "\n===>>> Third Weather Update" << endl;
    weatherStation->setWeatherReadings(70, 21, 29.2f);

    delete forecastDisplay;
    delete currentDisplay;
    delete weatherStation;

    return 0;
}
