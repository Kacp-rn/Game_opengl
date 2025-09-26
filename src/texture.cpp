// #include"texture.h"

// void Texture::is_exist()
// {
//     const fs::path directoryPath("/home/kacp_r/Dokumenty/Game/src");

//     try 
//     {
//         if (fs::exists(directoryPath) && fs::is_directory(directoryPath)) 
//         {
//             for (const auto& entry : fs::directory_iterator(directoryPath)) 
//             {
//                 std::cout << entry.path() << std::endl;
//                 //return true;
//             }
//         }
//         else 
//         {
//             std::cerr << "Katalog nie istnieje lub to nie jest katalog." << std::endl;
//             //return false;
//         }
//     }
//     catch (const fs::filesystem_error& e) 
//     {
//         std::cerr << "Błąd systemu plików: " << e.what() << std::endl;
//         //return false;
//     }
//    // return true;
// }