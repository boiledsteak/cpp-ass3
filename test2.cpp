// Function to sort objects based on mode3 and mode4
template<typename ObjectType>
void sortObjects(vector<ObjectType>& objects, const string& mode3, const string& mode4) 
{
    if (mode3 == "Pt. 1") 
    {
        if (mode4 == "ASC") 
        {
            // Sort based on Pt. 1 in ascending order
            sort(objects.begin(), objects.end(), [](const auto& obj1, const auto& obj2) {
                // Implement comparison logic based on Pt. 1
                // Example:
                return obj1.getPt1() < obj2.getPt1();
            });
        } 
        else if (mode4 == "DSC") 
        {
            // Sort based on Pt. 1 in descending order
            sort(objects.begin(), objects.end(), [](const auto& obj1, const auto& obj2) {
                // Implement comparison logic based on Pt. 1
                // Example:
                return obj1.getPt1() > obj2.getPt1();
            });
        }
    } 
    else if (mode3 == "Pt. 2") 
    {
        if (mode4 == "ASC") 
        {
            // Sort based on Pt. 2 in ascending order
            sort(objects.begin(), objects.end(), [](const auto& obj1, const auto& obj2) {
                // Implement comparison logic based on Pt. 2
                // Example:
                return obj1.getPt2() < obj2.getPt2();
            });
        } 
        else if (mode4 == "DSC") 
        {
            // Sort based on Pt. 2 in descending order
            sort(objects.begin(), objects.end(), [](const auto& obj1, const auto& obj2) {
                // Implement comparison logic based on Pt. 2
                // Example:
                return obj1.getPt2() > obj2.getPt2();
            });
        }
    } 
    else if (mode3 == "Length") 
    {
        if (mode4 == "ASC") 
        {
            // Sort based on Length in ascending order
            sort(objects.begin(), objects.end(), [](const auto& obj1, const auto& obj2) {
                // Implement comparison logic based on Length
                // Example:
                return obj1.getScalarValue() < obj2.getScalarValue();
            });
        } 
        else if (mode4 == "DSC") 
        {
            // Sort based on Length in descending order
            sort(objects.begin(), objects.end(), [](const auto& obj1, const auto& obj2) {
                // Implement comparison logic based on Length
                // Example:
                return obj1.getScalarValue() > obj2.getScalarValue();
            });
        }
    }
}
