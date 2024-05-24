#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

static bool Error = false;

class Package {
private:

    string name;
    string lastname;
    string location;
    string city;
    string state;
    int postalCodeSender;
    int postalCodeRecipient;
    double weight;
    double costPerOunce;

public:

    Package(const string& Name, const string& Lastname, const string& Location, const string& City, const string& State, int PostalCodeSender, int PostalCodeReceiver, double Weight, double CostPerOunce) {

        name = Name;
        lastname = Lastname;
        location = Location;
        city = City;
        state = State;
        postalCodeSender = PostalCodeSender;
        postalCodeRecipient = PostalCodeReceiver;
        weight = Weight > 0 ? Weight : 0;
        costPerOunce = CostPerOunce > 0 ? CostPerOunce : 0;

        if (Weight <= 0 || CostPerOunce <= 0) {
            Error = true;
            cout << "Weight and cost per ounce must be positive values !!!" << endl;
        }
    }

    double GetWeight() const {
        return weight;
    }

    virtual double calculateCost() const {
        return weight * costPerOunce;
    }
};

class TwoDayPackage : public Package {
private:

    double extraFee;

public:

    TwoDayPackage(const string& Name, const string& Lastname, const string& Location, const string& City, const string& State,
        int PostalCodeSender, int PostalCodeReceiver, double Weight, double CostPerOunce, double ExtraFee)

        : Package(Name, Lastname, Location, City, State, PostalCodeSender, PostalCodeReceiver, Weight, CostPerOunce) {

        extraFee = ExtraFee > 0 ? ExtraFee : 0;

        if (ExtraFee <= 0) {
            Error = true;
            cout << "Fee must be a positive value" << endl;
        }
    }

    double calculateCost() const override {
        return Package::calculateCost() + extraFee;
    }
};

class OverNightPackage : public Package {
private:
    double extraFeePerOunce;

public:
    OverNightPackage(const string& Name, const string& Lastname, const string& Location, const string& City, const string& State,
        int PostalCodeSender, int PostalCodeReceiver, double Weight, double CostPerOunce, double ExtraFeePerOunce)

        : Package(Name, Lastname, Location, City, State, PostalCodeSender, PostalCodeReceiver, Weight, CostPerOunce) {

        extraFeePerOunce = ExtraFeePerOunce > 0 ? ExtraFeePerOunce : 0;

        if (ExtraFeePerOunce <= 0) {
            Error = true;
            cout << "Additional fee per ounce must be a positive value" << endl;
        }
    }

    double calculateCost() const override {
        return Package::calculateCost() + (GetWeight() * extraFeePerOunce);
    }
};

class Container {
private:

    string postOffice;
    string senderName;
    string senderAddress;
    string senderPhone;
    string recipientName;
    string recipientAddress;
    string recipientPhone;
    int senderPostalCode;
    int recipientPostalCode;
    string alternativeDeliveryAddress;
    string postOfficeSupportPhone;
    double price;
    string size;
    string material;

    // extra perameters

    string contentsDescription;
    bool breakable;
    string alternativePhone;

public:
    Container(const string& PostOffice, const string& SenderName, const string& SenderAddress, const string& SenderPhone,
        const string& RecipientName, const string& RecipientAddress, const string& RecipientPhone,
        int SenderPostalCode, int RecipientPostalCode, const string& AlternativeDeliveryAddress,
        const string& PostOfficeSupportPhone, double Price, const string& Size, const string& Material,
        const string& ContentsDescription, bool Breakable, const string& AlternativePhone) {

        postOffice = PostOffice;
        senderName = SenderName;
        senderAddress = SenderAddress;
        senderPhone = SenderPhone;
        recipientName = RecipientName;
        recipientAddress = RecipientAddress;
        recipientPhone = RecipientPhone;
        senderPostalCode = SenderPostalCode;
        recipientPostalCode = RecipientPostalCode;
        alternativeDeliveryAddress = AlternativeDeliveryAddress;
        postOfficeSupportPhone = PostOfficeSupportPhone;
        price = Price;
        size = Size;
        material = Material;
        contentsDescription = ContentsDescription;
        breakable = Breakable;
        alternativePhone = AlternativePhone;
    }

    void displayInfo() const {

        cout << "Post Office: " << postOffice << endl;
        cout << "Sender Name: " << senderName << endl;
        cout << "Sender Address: " << senderAddress << endl;
        cout << "Sender Phone: " << senderPhone << endl;
        cout << "Recipient Name: " << recipientName << endl;
        cout << "Recipient Address: " << recipientAddress << endl;
        cout << "Recipient Phone: " << recipientPhone << endl;
        cout << "Sender Postal Code: " << senderPostalCode << endl;
        cout << "Recipient Postal Code: " << recipientPostalCode << endl;
        cout << "Alternative Delivery Address: " << alternativeDeliveryAddress << endl;
        cout << "Post Office Support Phone: " << postOfficeSupportPhone << endl;
        cout << "Price: " << price << endl;
        cout << "Size: " << size << endl;
        cout << "Material: " << material << endl;
        cout << "Contents Description: " << contentsDescription << endl;
        cout << "Breakable: " << (breakable ? "Yes" : "No") << endl;
        cout << "Alternative Phone: " << alternativePhone << endl;
    }
};

class Box : public Container {
public:
    Box(const string& PostOffice, const string& SenderName, const string& SenderAddress, const string& SenderPhone,
        const string& RecipientName, const string& RecipientAddress, const string& RecipientPhone,
        int SenderPostalCode, int RecipientPostalCode, const string& AlternativeDeliveryAddress,
        const string& PostOfficeSupportPhone, double Price, const string& Size, const string& Material,
        const string& ContentsDescription, bool Breakable, const string& AlternativePhone)

        : Container(PostOffice, SenderName, SenderAddress, SenderPhone, RecipientName, RecipientAddress, RecipientPhone,
            SenderPostalCode, RecipientPostalCode, AlternativeDeliveryAddress, PostOfficeSupportPhone, Price, Size, Material,
            ContentsDescription, Breakable, AlternativePhone) {}
};

class Envelope : public Container {
public:
    Envelope(const string& PostOffice, const string& SenderName, const string& SenderAddress, const string& SenderPhone,
        const string& RecipientName, const string& RecipientAddress, const string& RecipientPhone,
        int SenderPostalCode, int RecipientPostalCode, const string& AlternativeDeliveryAddress,
        const string& PostOfficeSupportPhone, double Price, const string& Size, const string& Material,
        const string& ContentsDescription, bool Breakable, const string& AlternativePhone)

        : Container(PostOffice, SenderName, SenderAddress, SenderPhone, RecipientName, RecipientAddress, RecipientPhone,
            SenderPostalCode, RecipientPostalCode, AlternativeDeliveryAddress, PostOfficeSupportPhone, Price, Size, Material,
            ContentsDescription, Breakable, AlternativePhone) {}
};

class BubbleEnvelope : public Envelope {
public:
    BubbleEnvelope(const string& PostOffice, const string& SenderName, const string& SenderAddress, const string& SenderPhone,
        const string& RecipientName, const string& RecipientAddress, const string& RecipientPhone,
        int SenderPostalCode, int RecipientPostalCode, const string& AlternativeDeliveryAddress,
        const string& PostOfficeSupportPhone, double Price, const string& Size, const string& Material,
        const string& ContentsDescription, bool Breakable, const string& AlternativePhone)

        : Envelope(PostOffice, SenderName, SenderAddress, SenderPhone, RecipientName, RecipientAddress, RecipientPhone,
            SenderPostalCode, RecipientPostalCode, AlternativeDeliveryAddress, PostOfficeSupportPhone, Price, Size, Material,
            ContentsDescription, Breakable, AlternativePhone) {}
};

class BlackNylonEnvelope : public Envelope {
public:
    BlackNylonEnvelope(const string& PostOffice, const string& SenderName, const string& SenderAddress, const string& SenderPhone,
        const string& RecipientName, const string& RecipientAddress, const string& RecipientPhone,
        int SenderPostalCode, int RecipientPostalCode, const string& AlternativeDeliveryAddress,
        const string& PostOfficeSupportPhone, double Price, const string& Size, const string& Material,
        const string& ContentsDescription, bool Breakable, const string& AlternativePhone)

        : Envelope(PostOffice, SenderName, SenderAddress, SenderPhone, RecipientName, RecipientAddress, RecipientPhone,
            SenderPostalCode, RecipientPostalCode, AlternativeDeliveryAddress, PostOfficeSupportPhone, Price, Size, Material,
            ContentsDescription, Breakable, AlternativePhone) {}
};

class MetallizedEnvelope : public Envelope {
public:
    MetallizedEnvelope(const string& PostOffice, const string& SenderName, const string& SenderAddress, const string& SenderPhone,
        const string& RecipientName, const string& RecipientAddress, const string& RecipientPhone,
        int SenderPostalCode, int RecipientPostalCode, const string& AlternativeDeliveryAddress,
        const string& PostOfficeSupportPhone, double Price, const string& Size, const string& Material,
        const string& ContentsDescription, bool Breakable, const string& AlternativePhone)

        : Envelope(PostOffice, SenderName, SenderAddress, SenderPhone, RecipientName, RecipientAddress, RecipientPhone,
            SenderPostalCode, RecipientPostalCode, AlternativeDeliveryAddress, PostOfficeSupportPhone, Price, Size, Material,
            ContentsDescription, Breakable, AlternativePhone) {}
};

class LaminatedEnvelope : public Envelope {
public:
    LaminatedEnvelope(const string& PostOffice, const string& SenderName, const string& SenderAddress, const string& SenderPhone,
        const string& RecipientName, const string& RecipientAddress, const string& RecipientPhone,
        int SenderPostalCode, int RecipientPostalCode, const string& AlternativeDeliveryAddress,
        const string& PostOfficeSupportPhone, double Price, const string& Size, const string& Material,
        const string& ContentsDescription, bool Breakable, const string& AlternativePhone)

        : Envelope(PostOffice, SenderName, SenderAddress, SenderPhone, RecipientName, RecipientAddress, RecipientPhone,
            SenderPostalCode, RecipientPostalCode, AlternativeDeliveryAddress, PostOfficeSupportPhone, Price, Size, Material,
            ContentsDescription, Breakable, AlternativePhone) {}
};

enum ServiceType {YourPost,ExpressMail,OrdinaryPost,CertifiedMail};

class Service {
private:
    ServiceType serviceType;

public:
    Service(ServiceType Type) : serviceType(Type) {}

    virtual void displayInfo() const {
        cout << "Service Type: " << serviceType << endl;
    }
};

class YourPostService : public Service {
public:
    YourPostService() : Service(YourPost) {}

    void displayInfo() const override {
        Service::displayInfo();
        cout << "YourPost Service selected." << endl;
    }
};

class ExpressMailService : public Service {
public:
    ExpressMailService() : Service(ExpressMail) {}

    string generateBarcode() const {
        srand(time(0));
        string barcode = "";
        for (int i = 0; i < 10; ++i) {
            barcode += to_string(rand() % 10);
        }
        return barcode;
    }

    void displayInfo() const override {
        Service::displayInfo();
        cout << "ExpressMail Service selected." << endl;
        cout << "Generated Barcode: " << generateBarcode() << endl;
    }
};

class OrdinaryPostService : public Service {
public:
    OrdinaryPostService() : Service(OrdinaryPost) {}

    void displayInfo() const override {
        Service::displayInfo();
        cout << "OrdinaryPost Service selected." << endl;
    }
};

class CertifiedMailService : public Service {
public:
    CertifiedMailService() : Service(CertifiedMail) {}

    void displayInfo() const override {
        Service::displayInfo();
        cout << "CertifiedMail Service selected." << endl;
    }
};

int main() {

    Package basicPackage("Mohammad", "Haqiqi", "Tarbiai 3", "Tabriz", "Azarbaijan Shargi", 12345, 67890, 10.0, 0.5);
    TwoDayPackage twoDayPackage("Walter", "White", "308 Negra Arroyo Lane", "Albuquerque", "New Mexico", 11111, 22222, 5.0, 0.5, 2.0);
    OverNightPackage overNightPackage("AmirAli", "Aghajani", "Golbarg 3", "Gorgan", "Golestan", 33333, 44444, 3.0, 0.5, 1.0);

    if (!Error) {
        cout << "Basic Package Shipping cost: " << basicPackage.calculateCost() << endl;
        cout << "Two Day Package Shipping cost: " << twoDayPackage.calculateCost() << endl;
        cout << "Overnight Package Shipping cost: " << overNightPackage.calculateCost() << endl;
    }
    else {
        cout << "Fix the error and try again" << endl;
    }

    Container container("Main Post Office", "Ali", "Main St", "555-1234", "Sara", "2nd St", "555-5678", 12345, 67890, "3rd St", "555-9999", 50.0, "Large", "Cardboard", "Books", false, "555-0000");
    Box box("Main Post Office", "Ali", "Main St", "555-1234", "Sara", "2nd St", "555-5678", 12345, 67890, "3rd St", "555-9999", 60.0, "Medium", "Plastic", "Toys", false, "555-0000");
    BubbleEnvelope bubbleEnvelope("Main Post Office", "Ali", "Main St", "555-1234", "Sara", "2nd St", "555-5678", 12345, 67890, "3rd St", "555-9999", 40.0, "Small", "Bubble Wrap", "Documents", true, "555-0000");

    cout << "\nContainer Information:\n";
    container.displayInfo();

    cout << "\nBox Information:\n";
    box.displayInfo();

    cout << "\nBubbleEnvelope Information:\n";
    bubbleEnvelope.displayInfo();

    Service* service = new ExpressMailService();
    cout << "\nService Information:\n";
    service->displayInfo();

    delete service;
    return 0;
}
