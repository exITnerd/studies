using Car_Park_Interfaces;
using System;

namespace Car_Park_Interfaces
{
    interface ICar
    {
        void Start();
        void Stop();
        void Drive();
        void FillTank();
    }

    interface IGasolineCar
    {
        void RefuelGasoline();
    }

    interface INaturalGasCar
    {
        void RefuelNaturalGas();
    }

    interface IElectricCar
    {
        void ChargeBattery();
    }
    class Program
    {
        static void Main(string[] args)
        {
            GasolineCar gasolineCar = new GasolineCar();
            NaturalGasCar naturalGasCar = new NaturalGasCar();
            ElectricCar electricCar = new ElectricCar();
            GasolineNaturalGasCar gasolineNaturalGasCar = new GasolineNaturalGasCar();
            GasolineElectricCar gasolineElectricCar = new GasolineElectricCar();

            Console.WriteLine("Test 1");
            TestDrive(gasolineNaturalGasCar);
            Console.WriteLine("\nTest 2");
            TestDrive(gasolineElectricCar);
        }

        static void TestDrive(ICar car)
        {
            car.FillTank();
            car.FillTank();
            car.Drive();
            car.Start();
            car.Start();
            car.Drive();
            car.Drive();
            car.Stop();
            car.Stop();
        }
    }

}
