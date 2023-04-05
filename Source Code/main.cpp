#include "includes.h"
#include "Config.cpp"
#include "Prompt.cpp"

// Variables
int choice;
int question = 0;
string GeneratedPrompt;
Prompt prompt;
Config Configuration;

int main()
{
    ClearScreen();
    Menu();
    return 0;
}

void Menu()
{
    ClearScreen();
    cout << "Waifu Prompt Generator" << endl;
    cout << "----------------------" << endl;
    cout << "1. Generate a prompt" << endl;
    cout << "2. Settings" << endl;
    cout << "3. Instructions" << endl;
    cout << "4. Exit" << endl;
    cout << "----------------------" << endl;
    cout << "Enter your choice: ";

    while (!(cin >> choice) || choice < 1 || choice > 4)
    {
        cout << "Invalid Option." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Sleep(2000);
        Menu();
    }
    switch (choice)
    {
    case 1:
        question = 0;
        generate_Prompt();
        break;
    case 2:
        Settings();
        break;
    case 3:
        Instructions();
        break;
    case 4:
        exit(0);
        break;
    }

    // Old version
    // switch (choice)
    // {
    // case 1:
    //     if (Configuration.advanced_Mode == true && Configuration.ultra_Horny_Mode == false)
    //     {
    //         question = 0;
    //         Generate_Prompt_Advanced_Questions();
    //     }
    //     else if (Configuration.ultra_Horny_Mode == true && Configuration.advanced_Mode == true)
    //     {
    //         question = 0;
    //         Generate_Prompt_Horny();
    //     }
    //     else
    //     {
    //         question = 0;
    //         Generate_Prompt_Basic_Questions();
    //     }
    //     break;
    // case 2:
    //     Settings();
    //     break;
    // case 3:
    //     Instructions();
    //     break;
    // case 4:
    //     exit(0);
    //     break;
    // }
}

void ClearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}

void Sleep(int time)
{
#ifdef _WIN32
    Sleep(time);
#else
    sleep(time / 1000);
#endif
}

void Settings()
{
    ClearScreen();
    cout << "Settings" << endl;
    cout << "----------------------" << endl;
    cout << "Basic Mode: " << !Configuration.advanced_Mode << endl;
    cout << "Advanced Mode: " << Configuration.advanced_Mode << endl;
    cout << "NSFW Mode: " << Configuration.adult_Mode << endl;
    cout << "Ultra Horny Mode: " << Configuration.ultra_Horny_Mode << endl;
    cout << "----------------------" << endl;
    cout << "1. Toggle Basic Mode" << endl;
    cout << "2. Toggle Advanced Mode" << endl;
    cout << "3. Toggle NSFW Mode" << endl;
    cout << "4. Toggle Ultra Horny Mode" << endl;
    cout << "5. Back" << endl;
    cout << "----------------------" << endl;
    cout << "Enter your choice: ";

    while (!(cin >> choice) || choice < 1 || choice > 5)
    {
        cout << "Invalid Option." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Sleep(2000);
        Settings();
    }

    switch (choice)
    {
    case 1:
        Configuration.advanced_Mode = false;
        Configuration.adult_Mode = false;
        Configuration.ultra_Horny_Mode = false;
        break;
    case 2:
        Configuration.advanced_Mode = true;
        Configuration.adult_Mode = false;
        Configuration.ultra_Horny_Mode = false;
        break;
    case 3:
        Configuration.adult_Mode = true;
        Configuration.advanced_Mode = true;
        Configuration.ultra_Horny_Mode = false;
        break;
    case 4:
        Configuration.adult_Mode = true;
        Configuration.advanced_Mode = true;
        Configuration.ultra_Horny_Mode = true;
        break;
    case 5:
        Menu();
        break;
    default:
        cout << "Invalid choice" << endl;
        Settings();
        break;
    }
    Settings();
}

void Debug()
{
    // Print all awnsers
    cout << "DEVELOPMENT VARIABLES" << endl;
    cout << "----------------------" << endl;
    cout << "AdvancedMode = " << Configuration.advanced_Mode << endl;
    cout << "AdultMode = " << Configuration.adult_Mode << endl;
    cout << "UltraHornyMode = " << Configuration.ultra_Horny_Mode << endl;
    cout << "----------------------" << endl;
    cout << "Gender = " << prompt.Gender << endl;
    cout << "Age = " << prompt.Age << endl;
    cout << "CharacterType = " << prompt.CharacterType << endl;
    cout << "HairColor = " << prompt.HairColor << endl;
    cout << "HairLenght = " << prompt.HairLenght << endl;
    cout << "EyeColor = " << prompt.EyeColor << endl;
    cout << "Clothing = " << prompt.Clothing << endl;
    cout << "BodyType = " << prompt.BodyType << endl;
    cout << "BreastSize = " << prompt.BreastSize << endl;
    cout << "CockSize = " << prompt.CockSize << endl;
    cout << "ButtSize = " << prompt.ButtSize << endl;
    cout << "Location = " << prompt.Location << endl;
    cout << "FacialExpression = " << prompt.FacialExpression << endl;
    cout << "Pose = " << prompt.Pose << endl;
    cout << "cameraPosition = " << prompt.cameraPosition << endl;
    cout << "PussySpreading = " << prompt.PussySpreading << endl;
    cout << "ButtSpreading = " << prompt.ButtSpreading << endl;
    cout << "Cum = " << prompt.Cum << endl;
    cout << "Extras = " << prompt.Extras << endl;
}

void Instructions()
{
    ClearScreen();
    cout << "The first screen you see is the menu." << endl;
    cout << "In the Menu you can choose to generate a prompt, go to the settings, see the instructions, or exit the program." << endl;
    cout << "In the settings you can toggle some settings." << endl;
    cout << "In the instructions you can see this message." << endl;
    cout << "----------------------" << endl;
    cout << "Generating a prompt" << endl;
    cout << "You will be asked some questions given some options to select from" << endl;
    cout << "Sometimes there will be options (Example hair color) where you will have to provide your own answer." << endl;
    cout << "----------------------" << endl;
    cout << "Press any key to go back to the menu." << endl;
    cin.get();
    cin.get();
    Menu();
}

string Prompt_Builder()
{
    cout << "[dev] Prompt_Builder() called" << endl;
    // Prompt for high quality images
    GeneratedPrompt = "masterpiece, best quality, solo, ";

    // Gender
    GeneratedPrompt += "1" + prompt.Gender + ", ";

    // Age
    if (prompt.Age > 18 && prompt.Age < 20)
    {
        GeneratedPrompt += "young_adult, ";
    }
    else if (prompt.Age > 20 && prompt.Age < 30)
    {
        GeneratedPrompt += "middle_aged, adult, ";
    }
    else if (prompt.Age > 30)
    {
        GeneratedPrompt += "old, adult, ";
    }
    else
    {
        GeneratedPrompt += "young_adult, ";
    }

    // Character Type
    if (prompt.Gender == "girl")
    {
        if (prompt.CharacterType == "cat")
        {
            GeneratedPrompt += "cat_ears, animal_ears, cat_tail, neko, ";
        }
        else if (prompt.CharacterType == "dog")
        {
            GeneratedPrompt += "dog_ears, animal_ears, dog_tail, catgirl, ";
        }
        else if (prompt.CharacterType == "fox")
        {
            GeneratedPrompt += "fox_ears, animal_ears, fox_tail, foxgirl, ";
        }
        else if (prompt.CharacterType == "wolf")
        {
            GeneratedPrompt += "wolf_ears, animal_ears, wolf_tail, wolfgirl, ";
        }
        else if (prompt.CharacterType == "bunny")
        {
            GeneratedPrompt += "bunny_ears, animal_ears, bunny_tail, bunnygirl, ";
        }
        else if (prompt.CharacterType == "cow")
        {
            GeneratedPrompt += "cow_ears, animal_ears, cow_tail, cowgirl, ";
        }
    }
    else if (prompt.Gender == "boy")
    {
        if (prompt.CharacterType == "cat")
        {
            GeneratedPrompt += "cat_ears, animal_ears, cat_tail, neko, catboy, ";
        }
        else if (prompt.CharacterType == "dog")
        {
            GeneratedPrompt += "dog_ears, animal_ears, dog_tail, dogboy, ";
        }
        else if (prompt.CharacterType == "fox")
        {
            GeneratedPrompt += "fox_ears, animal_ears, fox_tail, foxboy, ";
        }
        else if (prompt.CharacterType == "wolf")
        {
            GeneratedPrompt += "wolf_ears, animal_ears, wolf_tail, wolfboy, ";
        }
        else if (prompt.CharacterType == "bunny")
        {
            GeneratedPrompt += "bunny_ears, animal_ears, bunny_tail, bunnyboy, ";
        }
        else if (prompt.CharacterType == "cow")
        {
            GeneratedPrompt += "cow_ears, animal_ears, cow_tail, cowboy, ";
        }
    }

    // Hair Color/Lenght and Eye Color
    if (Configuration.advanced_Mode == true)
    {
        // Hair
        GeneratedPrompt += prompt.HairColor + "_hair, ";
        GeneratedPrompt += prompt.HairLenght + "_hair, ";

        // Eyes
        GeneratedPrompt += prompt.EyeColor + "_eyes, ";
    }

    // Clothing
    if (prompt.Gender == "girl")
    {
        if (prompt.Clothing == "Nude")
        {
            GeneratedPrompt += "nude, naked, barefoot, completely_nude, nipples, pussy,";
        }
        else if (prompt.Clothing == "Casual")
        {
            GeneratedPrompt += "shirt, jeans, casual_clothing, ";
        }
        else if (prompt.Clothing == "formal")
        {
            GeneratedPrompt += "coat, footwear, necktie, skirt, collared_shirt, jacket, jacket_on_shoulders, kneehighs, shirt, ";
        }
        else if (prompt.Clothing == "school_Uniform")
        {
            GeneratedPrompt += "braid, holding_strap, kneehighs, pleated_skirt, sailor_collar, school_uniform, shirt, short_sleeves, skirt, ";
        }
        else if (prompt.Clothing == "Swimsuit")
        {
            GeneratedPrompt += "bikini, cleavage, swimsuit, ";
        }
        else if (prompt.Clothing == "maid_Uniform")
        {
            GeneratedPrompt += "dress, ribbon, frilled_apron, maid_uniform, maid_headdress, maid_apron, maid_collar, maid_skirt, maid_gloves, maid_shoes, thighhighs, legwear, ";
        }
        else if (prompt.Clothing == "Underwear")
        {
            GeneratedPrompt += "underwear, bra, panties, underwear_only, ";
        }
        else if (prompt.Clothing == "Lingerie")
        {
            GeneratedPrompt += "black_bra, black_legwear, bra, cleavage, garter_belt, garter_straps, hairband, lace, lace-trimmed_bra, lace-trimmed_legwear, lace_trim, lingerie , panties, stockings, thighhighs, underwear, ";
        }
    }
    else if (prompt.Gender == "boy")
    {
        if (prompt.Clothing == "Nude")
        {
            GeneratedPrompt += "nude, naked, barefoot, completely_nude, nipples, penis,";
        }
        else if (prompt.Clothing == "Casual")
        {
            GeneratedPrompt += "shirt, jeans, casual_clothing, ";
        }
        else if (prompt.Clothing == "Formal")
        {
            GeneratedPrompt += "coat, necktie, collared_shirt, jacket, jacket_on_shoulders, shirt, ";
        }
        else if (prompt.Clothing == "school_Uniform")
        {
            GeneratedPrompt += "sailor_collar, school_uniform, shirt, short_sleeves, ";
        }
        else if (prompt.Clothing == "Swimsuit")
        {
            GeneratedPrompt += "swim_trunks, boardshorts, ";
        }
        else if (prompt.Clothing == "maid_Uniform")
        {
            GeneratedPrompt += "butler_uniform, tailcoat, white_gloves, bowtie, waistcoat, dress_shirt, dress_pants, formal_shoes, apron";
        }
        else if (prompt.Clothing == "Underwear")
        {
            GeneratedPrompt += "underwear, underwear_only, boxers, trunks, ";
        }
        else if (prompt.Clothing == "Lingerie")
        {
            GeneratedPrompt += "black_bra, black_legwear, bra, cleavage, garter_belt, garter_straps, hairband, lace, lace-trimmed_bra, lace-trimmed_legwear, lace_trim, lingerie , panties, stockings, thighhighs, underwear, ";
        }
    }

    // Body Type
    if (Configuration.advanced_Mode == true)
    {
        GeneratedPrompt += prompt.BodyType + "_body, ";
    }

    // Breasts/Cocks and Butt
    if (Configuration.adult_Mode == true)
    {
        // Breasts
        if (prompt.Gender == "girl")
        {
            if (prompt.BreastSize == "small")
            {
                GeneratedPrompt += "small_breasts, flat_breast, ";
            }
            else if (prompt.BreastSize == "medium")
            {
                GeneratedPrompt += prompt.BreastSize + " breasts, average_breast, ";
            }
            else if (prompt.BreastSize == "large")
            {
                GeneratedPrompt += prompt.BreastSize + " breasts, big_breast, above_average_breast, ";
            }
            else if (prompt.BreastSize == "huge")
            {
                GeneratedPrompt += prompt.BreastSize + " breasts, huge_breast, ";
            }
        }
        else
        {
            GeneratedPrompt += "";
        }

        if (prompt.Gender == "boy")
        {
            if (prompt.CockSize == "small")
            {
                GeneratedPrompt += " cock, small penis, ";
            }
            else if (prompt.CockSize == "medium")
            {
                GeneratedPrompt += prompt.BreastSize + " cock, average penis, ";
            }
            else if (prompt.CockSize == "large")
            {
                GeneratedPrompt += prompt.BreastSize + " cock, large penis, ";
            }
            else if (prompt.CockSize == "huge")
            {
                GeneratedPrompt += prompt.CockSize + " cock, huge penis, ";
            }
        }
        else
        {
            GeneratedPrompt += "";
        }

        // Butt
        if (prompt.ButtSize == "small")
        {
            GeneratedPrompt += "small_butt, flat_butt, ";
        }
        else if (prompt.ButtSize == "medium")
        {
            GeneratedPrompt += prompt.ButtSize + " butt, average_butt, ";
        }
        else if (prompt.ButtSize == "large")
        {
            GeneratedPrompt += prompt.ButtSize + " butt, big_butt, Above_average_butt, ";
        }
        else if (prompt.ButtSize == "huge")
        {
            GeneratedPrompt += prompt.ButtSize + " butt, huge_butt, ";
        }
    }

    // Location
    GeneratedPrompt += prompt.Location + ", ";

    if (Configuration.advanced_Mode == true)
    {
        // Facial Expression
        GeneratedPrompt += prompt.FacialExpression + ", ";
    }

    // Pose
    GeneratedPrompt += prompt.Pose + ", ";

    // Camera Position
    if (prompt.cameraPosition == "front")
    {
        GeneratedPrompt += "front_view, midshot, fullbody, ";
    }
    else if (prompt.cameraPosition == "back")
    {
        GeneratedPrompt += "back_view, midshot, fullbody,viewed_from_behind, viewed_from_back, ";
    }
    else if (prompt.cameraPosition == "upskirt")
    {
        GeneratedPrompt += "upskirt, upskirt_view, from below, pussy, anus, ass, view_from_below, ";
    }
    else if (prompt.cameraPosition == "POV")
    {
        GeneratedPrompt += "pov, ";
    }
    else if (prompt.cameraPosition == "closeup")
    {
        GeneratedPrompt += "closeup, extreme_close_up, ";
    }

    // Optionals

    if (Configuration.ultra_Horny_Mode == true)
    {
        // Pussy Spreading
        if (prompt.Gender == "girl")
        {
            if (prompt.PussySpreading == true)
            {
                GeneratedPrompt += "spread_pussy, pussy_juice, ";
            }
        }

        // Ass Spreading
        if (prompt.ButtSpreading == true)
        {
            GeneratedPrompt += "ass_grab, hand_on_ass, spread_anus, spread_ass, ";
        }

        // Cum / Juice
        if (prompt.Cum == true)
        {
            GeneratedPrompt += "cum, cum_in_pussy, cum_on_body, cumdrip, ejaculation, ";
        }
    }

    // Extras
    GeneratedPrompt += prompt.Extras;

    return GeneratedPrompt;
}

void generate_Prompt()
{

    if (question == 0)
    {
        ClearScreen(); // -------------------------------
        cout << "Question 1. Gender" << endl;
        cout << "----------------------" << endl;
        cout << "1. Male / Boy" << endl;
        cout << "2. Female / Girl" << endl;
        cout << "----------------------" << endl;
        cout << "101. Back to Menu" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice) || choice < 1 || choice > 2)
        {
            if (choice == 101)
            {
                Menu();
                generate_Prompt();
                break;
            }
            cout << "Invalid Option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(2000);
            generate_Prompt();
        }
        switch (choice)
        {
        case 1:
            prompt.Gender = "boy";
            break;
        case 2:
            prompt.Gender = "girl";
            break;
        }
        question++;
    }
    if (question == 1)
    {
        ClearScreen(); // -------------------------------
        cout << "Question 2. Age" << endl;
        cout << "----------------------" << endl;
        cout << "Enter a age between 18 and 30 (Example: '18' 26' '30')" << endl;
        cout << "----------------------" << endl;
        cout << "101. Back one Question" << endl;
        cout << "----------------------" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice) || choice < 18 || choice > 30)
        {
            if (choice == 101)
            {
                question--;
                generate_Prompt();
                break;
            }
            cout << "Invalid Option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(2000);
            generate_Prompt();
        }
        if (choice >= 18 && choice <= 30)
        {
            prompt.Age = choice;
        }
        question++;
    }

    if (question == 2)
    {
        ClearScreen(); // -------------------------------
        cout << "Question 3. Type Of Character" << endl;
        cout << "----------------------" << endl;
        cout << "1. Normal" << endl;
        cout << "2. Catgirl / CatBoy" << endl;
        cout << "3. Doggirl / DogBoy" << endl;
        cout << "4. Foxgirl / FoxBoy" << endl;
        cout << "5. Wolfgirl / WolfBoy" << endl;
        cout << "6. Bunnygirl / BunnyBoy" << endl;
        cout << "7. Cowgirl / CowBoy" << endl;
        cout << "----------------------" << endl;
        cout << "101. Back one Question" << endl;
        cout << "----------------------" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice) || choice < 1 || choice > 7)
        {
            if (choice == 101)
            {
                question--;
                generate_Prompt();
                break;
            }
            cout << "Invalid Option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(2000);
            generate_Prompt();
        }
        switch (choice)
        {
        case 1:
            prompt.CharacterType = "normal";
            break;
        case 2:
            prompt.CharacterType = "cat";
            break;
        case 3:
            prompt.CharacterType = "dog";
            break;
        case 4:
            prompt.CharacterType = "fox";
            break;
        case 5:
            prompt.CharacterType = "wolf";
            break;
        case 6:
            prompt.CharacterType = "bunny";
            break;
        case 7:
            prompt.CharacterType = "cow";
            break;
        }
        if (Configuration.advanced_Mode == true)
        {
            question++;
        }
        else
        {
            question = 6;
        }
    }

    // Questions for Advanced Mode, Hair Color and Lenght and Eye Color
    if (Configuration.advanced_Mode == true)
    {
        if (question == 3)
        {
            ClearScreen(); // -------------------------------
            cout << "Question C4. Hair Color" << endl;
            cout << "----------------------" << endl;
            cout << "Input a hair color (Example: 'red' 'blonde' 'black' 'purple')" << endl;
            cout << "----------------------" << endl;
            cout << "101. Back one Question" << endl;
            cout << "----------------------" << endl;
            cout << "Enter your choice: ";
            cin >> prompt.HairColor;
            if (prompt.HairColor == "101")
            {
                question--;
                generate_Prompt();
            }
            question++;
        }

        if (question == 4)
        {
            ClearScreen(); // -------------------------------
            cout << "Question C4.1 Hair Lenght" << endl;
            cout << "----------------------" << endl;
            cout << "1. Short" << endl;
            cout << "2. Medium" << endl;
            cout << "3. Long" << endl;
            cout << "----------------------" << endl;
            cout << "101. Back one Question" << endl;
            cout << "----------------------" << endl;
            cout << "Enter your choice: ";
            while (!(cin >> choice) || choice < 1 || choice > 3)
            {
                if (choice == 101)
                {
                    question--;
                    generate_Prompt();
                    break;
                }
                cout << "Invalid Option." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Sleep(2000);
                generate_Prompt();
            }
            switch (choice)
            {
            case 1:
                prompt.HairLenght = "short";
                break;
            case 2:
                prompt.HairLenght = "medium";
                break;
            case 3:
                prompt.HairLenght = "long";
                break;
            }
            question++;
        }

        if (question == 5)
        {
            ClearScreen(); // -------------------------------
            cout << "Question C4.2. Eye Color" << endl;
            cout << "----------------------" << endl;
            cout << "Input a eye color (Example: 'red' 'blue' 'black' 'purple')" << endl;
            cout << "----------------------" << endl;
            cout << "101. Back one Question" << endl;
            cout << "----------------------" << endl;
            cout << "Enter your choice: ";
            cin >> prompt.EyeColor;
            if (prompt.EyeColor == "101")
            {
                question--;
                generate_Prompt();
            }
            question++;
        }
    }
    // End of Advanced Mode Questions

    // Basic Mode Questions Continue
    if (question == 6)
    {
        ClearScreen(); // -------------------------------
        if (Configuration.adult_Mode == true && Configuration.ultra_Horny_Mode == true)
        {
            cout << "Question 4. Clothing" << endl;
            cout << "----------------------" << endl;
            cout << "1. Nude" << endl;
            cout << "2. Casual" << endl;
            cout << "3. Formal" << endl;
            cout << "4. School Uniform" << endl;
            cout << "5. Swimsuit" << endl;
            cout << "6. Maid Uniform" << endl;
            cout << "7. Underwear" << endl;
            cout << "8. Lingerie" << endl;
            cout << "----------------------" << endl;
            cout << "101. Back one Question" << endl;
            cout << "----------------------" << endl;
            cout << "Enter your choice: ";

            while (!(cin >> choice) || choice < 1 || choice > 8)
            {
                if (choice == 101)
                {
                    if (Configuration.advanced_Mode == true)
                    {
                        question--;
                    }
                    else
                    {
                        question = 2;
                    }
                    generate_Prompt();
                    break;
                }
                cout << "Invalid Option." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Sleep(2000);
                generate_Prompt();
            }
            switch (choice)
            {
            case 1:
                prompt.Clothing = "Nude";
                break;
            case 2:
                prompt.Clothing = "Casual";
                break;
            case 3:
                prompt.Clothing = "formal";
                break;
            case 4:
                prompt.Clothing = "school_Uniform";
                break;
            case 5:
                prompt.Clothing = "Swimsuit";
                break;
            case 6:
                prompt.Clothing = "maid_Uniform";
                break;
            case 7:
                prompt.Clothing = "Underwear";
                break;
            case 8:
                prompt.Clothing = "Lingerie";
                break;
            }
        }
        else if (Configuration.adult_Mode == true && Configuration.ultra_Horny_Mode == false)
        {
            cout << "Question 4. Clothing" << endl;
            cout << "----------------------" << endl;
            cout << "69. Nude" << endl;
            cout << "1. Casual" << endl;
            cout << "2. Formal" << endl;
            cout << "3. School Uniform" << endl;
            cout << "4. Swimsuit" << endl;
            cout << "5. Maid Uniform" << endl;
            cout << "6. Underwear" << endl;
            cout << "7. Lingerie" << endl;
            cout << "----------------------" << endl;
            cout << "101. Back one Question" << endl;
            cout << "----------------------" << endl;
            cout << "Enter your choice: ";

            while (!(cin >> choice) || choice < 1 || choice > 7)
            {
                if (choice == 101)
                {
                    if (Configuration.advanced_Mode == true)
                    {
                        question--;
                    }
                    else
                    {
                        question = 2;
                    }
                    generate_Prompt();
                    break;
                }
                if (choice == 69)
                {
                    prompt.Clothing = "Nude";
                    if (Configuration.advanced_Mode == true)
                    {
                        question++;
                        generate_Prompt();
                    }
                    else
                    {
                        question = 9;
                        generate_Prompt();
                    }
                }
                cout << "Invalid Option." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Sleep(2000);
                generate_Prompt();
            }
            switch (choice)
            {
            case 1:
                prompt.Clothing = "Casual";
                break;
            case 2:
                prompt.Clothing = "Formal";
                break;
            case 3:
                prompt.Clothing = "school_Uniform";
                break;
            case 4:
                prompt.Clothing = "Swimsuit";
                break;
            case 5:
                prompt.Clothing = "maid_Uniform";
                break;
            case 6:
                prompt.Clothing = "Underwear";
                break;
            }
        }
        else
        {
            cout << "Question 4. Clothing" << endl;
            cout << "----------------------" << endl;
            cout << "1. Casual" << endl;
            cout << "2. Formal" << endl;
            cout << "3. School Uniform" << endl;
            cout << "4. Swimsuit" << endl;
            cout << "5. Maid Uniform" << endl;
            cout << "6. Underwear" << endl;
            cout << "----------------------" << endl;
            cout << "101. Back one Question" << endl;
            cout << "----------------------" << endl;
            cout << "Enter your choice: ";

            while (!(cin >> choice) || choice < 1 || choice > 6)
            {
                if (choice == 101)
                {
                    if (Configuration.advanced_Mode == true)
                    {
                        question--;
                    }
                    else
                    {
                        question = 2;
                    }
                    generate_Prompt();
                    break;
                }
                cout << "Invalid Option." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Sleep(2000);
                generate_Prompt();
            }
            switch (choice)
            {
            case 1:
                prompt.Clothing = "Casual";
                break;
            case 2:
                prompt.Clothing = "formal";
                break;
            case 3:
                prompt.Clothing = "school_Uniform";
                break;
            case 4:
                prompt.Clothing = "Swimsuit";
                break;
            case 5:
                prompt.Clothing = "maid_Uniform";
                break;
            case 6:
                prompt.Clothing = "Underwear";
                break;
            }
        }
        if (Configuration.advanced_Mode == true)
        {
            question++;
        }
        else
        {
            question = 9;
        }
    }

    // Advanced Mode Questions Continue
    if (Configuration.advanced_Mode == true)
    {
        if (question == 7)
        {
            ClearScreen(); // -------------------------------
            cout << "Question C5. Body Type" << endl;
            cout << "----------------------" << endl;
            cout << "1. Skinny" << endl;
            cout << "2. Average" << endl;
            cout << "3. Athletic" << endl;
            cout << "4. Chubby" << endl;
            cout << "5. Fat" << endl;
            cout << "----------------------" << endl;
            cout << "101. Back one Question" << endl;
            cout << "----------------------" << endl;
            cout << "Enter your choice: ";
            while (!(cin >> choice) || choice < 1 || choice > 5)
            {
                if (choice == 101)
                {
                    question--;
                    generate_Prompt();
                    break;
                }
                cout << "Invalid Option." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Sleep(2000);
                generate_Prompt();
            }
            switch (choice)
            {
            case 1:
                prompt.BodyType = "skinny";
                break;
            case 2:
                prompt.BodyType = "average";
                break;
            case 3:
                prompt.BodyType = "athletic";
                break;
            case 4:
                prompt.BodyType = "chubby";
                break;
            case 5:
                prompt.BodyType = "fat";
                break;
            }
            question++;
        }

        if (question == 8)
        {
            if (Configuration.adult_Mode == true)
            {
                if (prompt.Gender == "girl")
                {
                    ClearScreen(); // -------------------------------
                    cout << "Question C5.A1 Breast Size" << endl;
                    cout << "----------------------" << endl;
                    cout << "1. small" << endl;
                    cout << "2. medium" << endl;
                    cout << "3. large" << endl;
                    cout << "4. huge" << endl;
                    cout << "----------------------" << endl;
                    cout << "101. Back one Question" << endl;
                    cout << "----------------------" << endl;
                    cout << "Enter your choice: ";
                    while (!(cin >> choice) || choice < 1 || choice > 4)
                    {
                        if (choice == 101)
                        {
                            question--;
                            generate_Prompt();
                            break;
                        }
                        cout << "Invalid Option." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        Sleep(2000);
                        generate_Prompt();
                    }
                    switch (choice)
                    {
                    case 1:
                        prompt.BreastSize = "small";
                        break;
                    case 2:
                        prompt.BreastSize = "medium";
                        break;
                    case 3:
                        prompt.BreastSize = "large";
                        break;
                    case 4:
                        prompt.BreastSize = "huge";
                        break;
                    }

                    ClearScreen(); // -------------------------------
                    cout << "Question C5.A2 Butt Size" << endl;
                    cout << "----------------------" << endl;
                    cout << "1. small" << endl;
                    cout << "2. medium" << endl;
                    cout << "3. large" << endl;
                    cout << "4. huge" << endl;
                    cout << "----------------------" << endl;
                    cout << "101. Back one Question" << endl;
                    cout << "----------------------" << endl;
                    cout << "Enter your choice: ";
                    while (!(cin >> choice) || choice < 1 || choice > 4)
                    {
                        if (choice == 101)
                        {
                            question--;
                            generate_Prompt();
                            break;
                        }
                        cout << "Invalid Option." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        Sleep(2000);
                        generate_Prompt();
                    }
                    switch (choice)
                    {
                    case 1:
                        prompt.ButtSize = "small";
                        break;
                    case 2:
                        prompt.ButtSize = "medium";
                        break;
                    case 3:
                        prompt.ButtSize = "large";
                        break;
                    case 4:
                        prompt.ButtSize = "huge";
                        break;
                    }
                }
                else
                {
                    ClearScreen(); // -------------------------------
                    cout << "Question C5.A1 Cock Size" << endl;
                    cout << "----------------------" << endl;
                    cout << "1. small" << endl;
                    cout << "2. medium" << endl;
                    cout << "3. large" << endl;
                    cout << "4. huge" << endl;
                    cout << "----------------------" << endl;
                    cout << "101. Back one Question" << endl;
                    cout << "----------------------" << endl;
                    cout << "Enter your choice: ";
                    while (!(cin >> choice) || choice < 1 || choice > 4)
                    {
                        if (choice == 101)
                        {
                            question--;
                            generate_Prompt();
                            break;
                        }
                        cout << "Invalid Option." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        Sleep(2000);
                        generate_Prompt();
                    }
                    switch (choice)
                    {
                    case 1:
                        prompt.CockSize = "small";
                        break;
                    case 2:
                        prompt.CockSize = "medium";
                        break;
                    case 3:
                        prompt.CockSize = "large";
                        break;
                    case 4:
                        prompt.CockSize = "huge";
                        break;
                    }

                    ClearScreen(); // -------------------------------
                    cout << "Question C5.A2 Butt Size" << endl;
                    cout << "----------------------" << endl;
                    cout << "1. small" << endl;
                    cout << "2. medium" << endl;
                    cout << "3. large" << endl;
                    cout << "4. huge" << endl;
                    cout << "----------------------" << endl;
                    cout << "101. Back one Question" << endl;
                    cout << "----------------------" << endl;
                    cout << "Enter your choice: ";
                    while (!(cin >> choice) || choice < 1 || choice > 4)
                    {
                        if (choice == 101)
                        {
                            question--;
                            generate_Prompt();
                            break;
                        }
                        cout << "Invalid Option." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        Sleep(2000);
                        generate_Prompt();
                    }
                    switch (choice)
                    {
                    case 1:
                        prompt.ButtSize = "small";
                        break;
                    case 2:
                        prompt.ButtSize = "medium";
                        break;
                    case 3:
                        prompt.ButtSize = "large";
                        break;
                    case 4:
                        prompt.ButtSize = "huge";
                        break;
                    }
                }
            }
            question++;
        }
    }
    // Advanced Mode Questions End

    // Basic Mode Questions Start
    if (question == 9)
    {
        ClearScreen(); // -------------------------------
        cout << "Question 5. Location" << endl;
        cout << "----------------------" << endl;
        cout << "Input a location (Example: 'Couch' 'Beach' 'Outside')" << endl;
        cout << "----------------------" << endl;
        cout << "101. Back one Question" << endl;
        cout << "----------------------" << endl;
        cout << "Enter your choice: ";
        cin >> prompt.Location;
        if (prompt.Location == "101")
        {
            if (Configuration.adult_Mode == true)
            {
                question--;
                generate_Prompt();
            }
            else if (Configuration.advanced_Mode == true && Configuration.adult_Mode == false)
            {
                question = 7;
                generate_Prompt();
            }
            else
            {
                question = 6;
                generate_Prompt();
            }
        }
        if (Configuration.advanced_Mode == true)
        {
            question++;
        }
        else
        {
            question = 11;
        }
    }
    // Basic Mode Questions End

    // Advanced Mode Questions Start
    if (Configuration.advanced_Mode == true)
    {
        if (question == 10)
        {
            ClearScreen(); // -------------------------------
            if (Configuration.ultra_Horny_Mode == true)
            {
                cout << "Question C5. Facial Expression" << endl;
                cout << "----------------------" << endl;
                cout << "1. Ahegao" << endl;
                cout << "2. Happy" << endl;
                cout << "3. Sad" << endl;
                cout << "4. Angry" << endl;
                cout << "5. Surprised" << endl;
                cout << "6. Neutral" << endl;
                cout << "7. Blushing" << endl;
                cout << "8. Smiling" << endl;
                cout << "9. Focused" << endl;
                cout << "----------------------" << endl;
                cout << "101. Back one Question" << endl;
                cout << "----------------------" << endl;
                cout << "Enter your choice: ";
                while (!(cin >> choice) || choice < 1 || choice > 9)
                {
                    if (choice == 101)
                    {
                        question--;
                        generate_Prompt();
                        break;
                    }
                    cout << "Invalid Option." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    Sleep(2000);
                    generate_Prompt();
                }
                switch (choice)
                {
                case 1:
                    prompt.FacialExpression = "ahegao";
                    break;
                case 2:
                    prompt.FacialExpression = "happy";
                    break;
                case 3:
                    prompt.FacialExpression = "sad";
                    break;
                case 4:
                    prompt.FacialExpression = "angry";
                    break;
                case 5:
                    prompt.FacialExpression = "surprised";
                    break;
                case 6:
                    prompt.FacialExpression = "neutral";
                    break;
                case 7:
                    prompt.FacialExpression = "blushing";
                    break;
                case 8:
                    prompt.FacialExpression = "smiling";
                    break;
                case 9:
                    prompt.FacialExpression = "focused";
                    break;
                }
            }
            else
            {
                cout << "Question C5. Facial Expression" << endl;
                cout << "----------------------" << endl;
                cout << "1. Happy" << endl;
                cout << "2. Sad" << endl;
                cout << "3. Angry" << endl;
                cout << "4. Surprised" << endl;
                cout << "5. Neutral" << endl;
                cout << "6. Blushing" << endl;
                cout << "7. Smiling" << endl;
                cout << "8. Focused" << endl;
                cout << "----------------------" << endl;
                cout << "101. Back one Question" << endl;
                cout << "----------------------" << endl;
                cout << "Enter your choice: ";
                while (!(cin >> choice) || choice < 1 || choice > 8)
                {
                    if (choice == 101)
                    {
                        question--;
                        generate_Prompt();
                        break;
                    }
                    cout << "Invalid Option." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    Sleep(2000);
                    generate_Prompt();
                }
                switch (choice)
                {
                case 1:
                    prompt.FacialExpression = "happy";
                    break;
                case 2:
                    prompt.FacialExpression = "sad";
                    break;
                case 3:
                    prompt.FacialExpression = "angry";
                    break;
                case 4:
                    prompt.FacialExpression = "surprised";
                    break;
                case 5:
                    prompt.FacialExpression = "neutral";
                    break;
                case 6:
                    prompt.FacialExpression = "blushing";
                    break;
                case 7:
                    prompt.FacialExpression = "smiling";
                    break;
                case 8:
                    prompt.FacialExpression = "focused";
                    break;
                }
            }

            question++;
        }
    }
    // Advanced Mode Questions End

    // Basic Mode Questions Start
    if (question == 11)
    {
        ClearScreen(); // -------------------------------
        cout << "Question 6. Pose" << endl;
        cout << "----------------------" << endl;
        cout << "1. Standing" << endl;
        cout << "2. Sitting" << endl;
        cout << "3. Laying" << endl;
        cout << "4. Kneeling" << endl;
        cout << "5. Crouching" << endl;
        cout << "6. Sleeping" << endl;
        cout << "7. Streching" << endl;
        cout << "8. Standing on one foot" << endl;
        cout << "9. Cross-legged" << endl;
        cout << "10. Bending over" << endl;
        cout << "----------------------" << endl;
        cout << "101. Back one Question" << endl;
        cout << "----------------------" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice) || choice < 1 || choice > 10)
        {
            if (choice == 101)
            {
                if (Configuration.advanced_Mode == true)
                {
                    question--;
                }
                else
                {
                    question = 9;
                }
                generate_Prompt();
                break;
            }
            cout << "Invalid Option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(2000);
            generate_Prompt();
        }
        switch (choice)
        {
        case 1:
            prompt.Pose = "standing";
            break;
        case 2:
            prompt.Pose = "sitting";
            break;
        case 3:
            prompt.Pose = "laying";
            break;
        case 4:
            prompt.Pose = "kneeling";
            break;
        case 5:
            prompt.Pose = "crouching";
            break;
        case 6:
            prompt.Pose = "sleeping";
            break;
        case 7:
            prompt.Pose = "streching";
            break;
        case 8:
            prompt.Pose = "standing_on_one_foot";
            break;
        case 9:
            prompt.Pose = "cross_legged";
            break;
        case 10:
            prompt.Pose = "bending_over";
            break;
        }
        if (Configuration.advanced_Mode == true)
        {
            question++;
        }
        else
        {
            question = 16;
        }
    }
    // Basic Mode Questions End

    // Advanced Mode Questions Start
    if (Configuration.advanced_Mode == true)
    {
        ClearScreen(); // -------------------------------
        if (question == 12 && Configuration.adult_Mode == true)
        {
            cout << "Question C6. Camera Position" << endl;
            cout << "----------------------" << endl;
            cout << "1. Front" << endl;
            cout << "2. Back" << endl;
            cout << "3. Upskirt" << endl;
            cout << "4. POV" << endl;
            cout << "5. CloseUp" << endl;
            cout << "----------------------" << endl;
            cout << "101. Back one Question" << endl;
            cout << "----------------------" << endl;
            cout << "Enter your choice: ";
            while (!(cin >> choice) || choice < 1 || choice > 5)
            {
                if (choice == 101)
                {
                    question--;
                    generate_Prompt();
                    break;
                }
                cout << "Invalid Option." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Sleep(2000);
                generate_Prompt();
            }
            switch (choice)
            {
            case 1:
                prompt.cameraPosition = "front";
                break;
            case 2:
                prompt.cameraPosition = "back";
                break;
            case 3:
                prompt.cameraPosition = "upskirt";
                break;
            case 4:
                prompt.cameraPosition = "pov";
                break;
            case 5:
                prompt.cameraPosition = "closeup";
                break;
            }
            if (Configuration.ultra_Horny_Mode == true)
            {
                question++;
            }
            else
            {
                question = 16;
            }
        }
        else if (question == 12 && Configuration.adult_Mode == false)
        {
            cout << "Question C6. Camera Position" << endl;
            cout << "----------------------" << endl;
            cout << "1. Front" << endl;
            cout << "2. Back" << endl;
            cout << "----------------------" << endl;
            cout << "101. Back one Question" << endl;
            cout << "----------------------" << endl;
            cout << "Enter your choice: ";
            while (!(cin >> choice) || choice < 1 || choice > 2)
            {
                if (choice == 101)
                {
                    question--;
                    generate_Prompt();
                    break;
                }
                cout << "Invalid Option." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Sleep(2000);
                generate_Prompt();
            }
            switch (choice)
            {
            case 1:
                prompt.cameraPosition = "front";
                break;
            case 2:
                prompt.cameraPosition = "back";
                break;
            }
            if (Configuration.ultra_Horny_Mode == true)
            {
                question++;
            }
            else
            {
                question = 16;
            }
        }
    }

    // Ultra-Horny-Mode Questions
    if (question == 13 && Configuration.ultra_Horny_Mode == true)
    {
        if (prompt.Gender == "girl")
        {
            ClearScreen(); // -------------------------------
            cout << "Question GA6. Pussy Spreading" << endl;
            cout << "----------------------" << endl;
            cout << "1. True" << endl;
            cout << "2. False" << endl;
            cout << "----------------------" << endl;
            cout << "101. Back one Question" << endl;
            cout << "----------------------" << endl;
            cout << "Enter your choice: ";
            while (!(cin >> choice) || choice < 1 || choice > 2)
            {
                if (choice == 101)
                {
                    question--;
                    generate_Prompt();
                    break;
                }
                cout << "Invalid Option." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Sleep(2000);
                generate_Prompt();
            }

            switch (choice)
            {
            case 1:
                prompt.PussySpreading = true;
                break;
            case 2:
                prompt.PussySpreading = false;
                break;
            }
        }
        question++;
    }

    if (question == 14 && Configuration.ultra_Horny_Mode == true)
    {
        ClearScreen(); // -------------------------------
        cout << "Question A6. Ass Spreading" << endl;
        cout << "----------------------" << endl;
        cout << "1. True" << endl;
        cout << "2. False" << endl;
        cout << "----------------------" << endl;
        cout << "101. Back one Question" << endl;
        cout << "----------------------" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice) || choice < 1 || choice > 2)
        {
            if (choice == 101)
            {
                if (prompt.Gender == "girl")
                {
                    question--;
                }
                else
                {
                    question = 12;
                }
                generate_Prompt();
                break;
            }
            cout << "Invalid Option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(2000);
            generate_Prompt();
        }

        switch (choice)
        {
        case 1:
            prompt.ButtSpreading = true;
            break;
        case 2:
            prompt.ButtSpreading = false;
            break;
        }
        question++;
    }

    if (question == 15 && Configuration.ultra_Horny_Mode == true)
    {
        ClearScreen(); // -------------------------------
        cout << "Question A5.1 Cum / Juice" << endl;
        cout << "----------------------" << endl;
        cout << "1. True" << endl;
        cout << "2. False" << endl;
        cout << "----------------------" << endl;
        cout << "101. Back one Question" << endl;
        cout << "----------------------" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice) || choice < 1 || choice > 2)
        {
            if (choice == 101)
            {
                question--;
                generate_Prompt();
                break;
            }
            cout << "Invalid Option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(2000);
            generate_Prompt();
        }

        switch (choice)
        {
        case 1:
            prompt.Cum = true;
            break;
        case 2:
            prompt.Cum = false;
            break;
        }
        question++;
    }
    // Ultra-Horny-Mode Questions End

    // Advanced Mode Questions End

    if (question == 16)
    {
        ClearScreen(); // -------------------------------
        cout << "Question (I AINT COUNTING MAN). Extras" << endl;
        cout << "----------------------" << endl;
        cout << "Input any extras (Example: 'Skirt, Thigh_Highs, Blue_Boots, Phone_in_hand)" << endl;
        cout << "----------------------" << endl;
        cout << "111. Leave blank" << endl;
        cout << "101. Back one Question" << endl;
        cout << "----------------------" << endl;
        cout << "Enter your choice: ";
        cin >> prompt.Extras;
        if (prompt.Extras == "101")
        {
            if (Configuration.ultra_Horny_Mode == true && Configuration.advanced_Mode == true)
            {
                question--;
            }
            else if (Configuration.ultra_Horny_Mode == false && Configuration.advanced_Mode == true)
            {
                question = 12;
            }
            else if (Configuration.ultra_Horny_Mode == false && Configuration.advanced_Mode == false)
            {
                question = 11;
            }
            generate_Prompt();
        }
        else if (prompt.Extras == "111")
        {
            prompt.Extras = "";
        }
        question++;
    }

    if (question == 17)
    {
        // Print out the finished built prompt
        ClearScreen(); // -------------------------------

        // Debugging
        if (Configuration.show_All_Awnsers == true)
        {
            Debug();
        }
        cout << "Your prompt is: " << endl;
        cout << Prompt_Builder() << endl;
        cout << "----------------------" << endl;
        cout << "1. Generate another prompt" << endl;
        cout << "2. Menu" << endl;
        cout << "----------------------" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice) || choice < 1 || choice > 2)
        {
            cout << "Invalid Option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(2000);
            generate_Prompt();
        }
        switch (choice)
        {
        case 1:
            question = 0;
            generate_Prompt();
            break;
        case 2:
            Menu();
            break;
        }
    }
}