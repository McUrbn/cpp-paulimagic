//
//  elements.cpp
//  paulimagic
//
//  Created by Seifert on 18.04.15.
//  Copyright (c) 2015 Urban Seifert. All rights reserved.
//

#include "elements.h"
#include "tensorproduct.h"
#include "paulimatrix.h"

#include <array>

#include <iostream>

auto IzH0zX (int power, const std::vector<int> &vec) -> int {
    switch(power) {
        case 1: return IzH0z1(vec);
        case 2: return IzH0z2(vec);
        case 3: return IzH0z3(vec);
        case 4: return IzH0z4(vec);
        case 5: return IzH0z5(vec);
        case 6: return IzH0z6(vec);
        case 7: return IzH0z7(vec);
        default: std::cout << "no function found" << std::endl; return 0;
    }
}

auto IzH0z1 (const std::vector<int> &vec) -> int {
    std::size_t N = vec.size(); // Number of bath spins
    
    std::complex<int> sum = 0;
    auto array = std::array<PauliMatrix, 3>{{PM::X, PM::Y, PM::Z}};
    for (std::size_t k0 = 0; k0 < N+1; ++k0) {
        auto spin0 = TensorProduct(N+1);
        spin0.set(k0,array[2]);
        
        for (std::size_t k1 = 0; k1 < N+1; ++k1) {
            auto spin1 = TensorProduct(N+1);
            spin1.set(k1,array[2]);
            auto prod0 = spin0*spin1;
            
            for (std::size_t i0 = 0; i0 < 3; ++i0) {
                auto spin2 = TensorProduct(N+1);
                spin2.set(0,array[i0]);
                auto prod1 = prod0*spin2;
                for (std::size_t j0 = 1; j0 < N+1; ++j0) {
                    if (!vec[j0-1]) {
                        continue;
                    }
                    auto spin3 = TensorProduct(N+1);
                    spin3.set(j0,array[i0]);
                    auto prod2 = prod1*spin3;
                    
                    sum += (prod2).trace()*vec[j0-1];
                }
            }
        }
    }
    
    
    sum /= pow(2.0, N+1); // Divide by DOS
    // sum /= pow(2.0, 2); // Spin = sigma/2
    return (int)sum.real();
}

auto IzH0z2 (const std::vector<int> &vec) -> int {
    std::size_t N = vec.size(); // Number of bath spins
    
    std::complex<int> sum = 0;
    auto array = std::array<PauliMatrix, 3>{{PM::X, PM::Y, PM::Z}};
    for (std::size_t k0 = 0; k0 < N+1; ++k0) {
        auto spin0 = TensorProduct(N+1);
        spin0.set(k0,array[2]);
        
        for (std::size_t k1 = 0; k1 < N+1; ++k1) {
            auto spin1 = TensorProduct(N+1);
            spin1.set(k1,array[2]);
            auto prod0 = spin0*spin1;
            
            for (std::size_t i0 = 0; i0 < 3; ++i0) {
                auto spin2 = TensorProduct(N+1);
                spin2.set(0,array[i0]);
                auto prod1 = prod0*spin2;
                for (std::size_t j0 = 1; j0 < N+1; ++j0) {
                    if (!vec[j0-1]) {
                        continue;
                    }
                    auto spin3 = TensorProduct(N+1);
                    spin3.set(j0,array[i0]);
                    auto prod2 = prod1*spin3;
                    
                    for (std::size_t i1 = 0; i1 < 3; ++i1) {
                        auto spin4 = TensorProduct(N+1);
                        spin4.set(0,array[i1]);
                        auto prod3 = prod2*spin4;
                        for (std::size_t j1 = 1; j1 < N+1; ++j1) {
                            if (!vec[j1-1]) {
                                continue;
                            }
                            auto spin5 = TensorProduct(N+1);
                            spin5.set(j1,array[i1]);
                            auto prod4 = prod3*spin5;
                            
                            
                            
                            sum += (prod4).trace()*vec[j0-1]*vec[j1-1];
                            
                            
                            
                            
                            
                        }
                    }
                }
            }
        }
    }
    
    
    sum /= pow(2.0, N+1); // Divide by DOS
    // sum /= pow(2.0, 2); // Spin = sigma/2
    return (int)sum.real();
}


auto IzH0z3 (const std::vector<int> &vec) -> int {
    std::size_t N = vec.size(); // Number of bath spins
    
    std::complex<int> sum = 0;
    auto array = std::array<PauliMatrix, 3>{{PM::X, PM::Y, PM::Z}};
    for (std::size_t k0 = 0; k0 < N+1; ++k0) {
        auto spin0 = TensorProduct(N+1);
        spin0.set(k0,array[2]);
        
        for (std::size_t k1 = 0; k1 < N+1; ++k1) {
            auto spin1 = TensorProduct(N+1);
            spin1.set(k1,array[2]);
            auto prod0 = spin0*spin1;
            
            for (std::size_t i0 = 0; i0 < 3; ++i0) {
                auto spin2 = TensorProduct(N+1);
                spin2.set(0,array[i0]);
                auto prod1 = prod0*spin2;
                for (std::size_t j0 = 1; j0 < N+1; ++j0) {
                    if (!vec[j0-1]) {
                        continue;
                    }
                    auto spin3 = TensorProduct(N+1);
                    spin3.set(j0,array[i0]);
                    auto prod2 = prod1*spin3;
                    
                    for (std::size_t i1 = 0; i1 < 3; ++i1) {
                        auto spin4 = TensorProduct(N+1);
                        spin4.set(0,array[i1]);
                        auto prod3 = prod2*spin4;
                        for (std::size_t j1 = 1; j1 < N+1; ++j1) {
                            if (!vec[j1-1]) {
                                continue;
                            }
                            auto spin5 = TensorProduct(N+1);
                            spin5.set(j1,array[i1]);
                            auto prod4 = prod3*spin5;
                            
                            for (std::size_t i2 = 0; i2 < 3; ++i2) {
                                auto spin6 = TensorProduct(N+1);
                                spin6.set(0,array[i2]);
                                auto prod5 = prod4*spin6;
                                for (std::size_t j2 = 1; j2 < N+1; ++j2) {
                                    if (!vec[j2-1]) {
                                        continue;
                                    }
                                    auto spin7 = TensorProduct(N+1);
                                    spin7.set(j2,array[i2]);
                                    auto prod6 = prod5*spin7;
                                    
                                    
                                    
                                    
                                    
                                    sum += (prod6).trace()*vec[j0-1]*vec[j1-1]*vec[j2-1];
                                    
                                    
                                    
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    sum /= pow(2.0, N+1); // Divide by DOS
    // sum /= pow(2.0, 2); // Spin = sigma/2
    return (int)sum.real();
}


auto IzH0z4 (const std::vector<int> &vec) -> int {
    std::size_t N = vec.size(); // Number of bath spins
    
    std::complex<int> sum = 0;
    auto array = std::array<PauliMatrix, 3>{{PM::X, PM::Y, PM::Z}};
    for (std::size_t k0 = 0; k0 < N+1; ++k0) {
        auto spin0 = TensorProduct(N+1);
        spin0.set(k0,array[2]);
        
        for (std::size_t k1 = 0; k1 < N+1; ++k1) {
            auto spin1 = TensorProduct(N+1);
            spin1.set(k1,array[2]);
            auto prod0 = spin0*spin1;
            
            for (std::size_t i0 = 0; i0 < 3; ++i0) {
                auto spin2 = TensorProduct(N+1);
                spin2.set(0,array[i0]);
                auto prod1 = prod0*spin2;
                for (std::size_t j0 = 1; j0 < N+1; ++j0) {
                    if (!vec[j0-1]) {
                        continue;
                    }
                    auto spin3 = TensorProduct(N+1);
                    spin3.set(j0,array[i0]);
                    auto prod2 = prod1*spin3;
                    
                    for (std::size_t i1 = 0; i1 < 3; ++i1) {
                        auto spin4 = TensorProduct(N+1);
                        spin4.set(0,array[i1]);
                        auto prod3 = prod2*spin4;
                        for (std::size_t j1 = 1; j1 < N+1; ++j1) {
                            if (!vec[j1-1]) {
                                continue;
                            }
                            auto spin5 = TensorProduct(N+1);
                            spin5.set(j1,array[i1]);
                            auto prod4 = prod3*spin5;
                            
                            for (std::size_t i2 = 0; i2 < 3; ++i2) {
                                auto spin6 = TensorProduct(N+1);
                                spin6.set(0,array[i2]);
                                auto prod5 = prod4*spin6;
                                for (std::size_t j2 = 1; j2 < N+1; ++j2) {
                                    if (!vec[j2-1]) {
                                        continue;
                                    }
                                    auto spin7 = TensorProduct(N+1);
                                    spin7.set(j2,array[i2]);
                                    auto prod6 = prod5*spin7;
                                    
                                    for (std::size_t i3 = 0; i3 < 3; ++i3) {
                                        auto spin8 = TensorProduct(N+1);
                                        spin8.set(0,array[i3]);
                                        auto prod7 = prod6*spin8;
                                        for (std::size_t j3 = 1; j3 < N+1; ++j3) {
                                            if (!vec[j3-1]) {
                                                continue;
                                            }
                                            auto spin9 = TensorProduct(N+1);
                                            spin9.set(j3,array[i3]);
                                            auto prod8 = prod7*spin9;
                                            
                                            
                                            
                                            sum += (prod8).trace()*vec[j0-1]*vec[j1-1]*vec[j2-1]*vec[j3-1];
                                            
                                            
                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    sum /= pow(2.0, N+1); // Divide by DOS
    // sum /= pow(2.0, 2); // Spin = sigma/2
    return (int)sum.real();
}

auto IzH0z5 (const std::vector<int> &vec) -> int {
    std::size_t N = vec.size(); // Number of bath spins
    
    std::complex<int> sum = 0;
    auto array = std::array<PauliMatrix, 3>{{PM::X, PM::Y, PM::Z}};
    for (std::size_t k0 = 0; k0 < N+1; ++k0) {
        auto spin0 = TensorProduct(N+1);
        spin0.set(k0,array[2]);
        
        for (std::size_t k1 = 0; k1 < N+1; ++k1) {
            auto spin1 = TensorProduct(N+1);
            spin1.set(k1,array[2]);
            auto prod0 = spin0*spin1;
            
            for (std::size_t i0 = 0; i0 < 3; ++i0) {
                auto spin2 = TensorProduct(N+1);
                spin2.set(0,array[i0]);
                auto prod1 = prod0*spin2;
                for (std::size_t j0 = 1; j0 < N+1; ++j0) {
                    if (!vec[j0-1]) {
                        continue;
                    }
                    auto spin3 = TensorProduct(N+1);
                    spin3.set(j0,array[i0]);
                    auto prod2 = prod1*spin3;
                    
                    for (std::size_t i1 = 0; i1 < 3; ++i1) {
                        auto spin4 = TensorProduct(N+1);
                        spin4.set(0,array[i1]);
                        auto prod3 = prod2*spin4;
                        for (std::size_t j1 = 1; j1 < N+1; ++j1) {
                            if (!vec[j1-1]) {
                                continue;
                            }
                            auto spin5 = TensorProduct(N+1);
                            spin5.set(j1,array[i1]);
                            auto prod4 = prod3*spin5;
                            
                            for (std::size_t i2 = 0; i2 < 3; ++i2) {
                                auto spin6 = TensorProduct(N+1);
                                spin6.set(0,array[i2]);
                                auto prod5 = prod4*spin6;
                                for (std::size_t j2 = 1; j2 < N+1; ++j2) {
                                    if (!vec[j2-1]) {
                                        continue;
                                    }
                                    auto spin7 = TensorProduct(N+1);
                                    spin7.set(j2,array[i2]);
                                    auto prod6 = prod5*spin7;
                                    
                                    for (std::size_t i3 = 0; i3 < 3; ++i3) {
                                        auto spin8 = TensorProduct(N+1);
                                        spin8.set(0,array[i3]);
                                        auto prod7 = prod6*spin8;
                                        for (std::size_t j3 = 1; j3 < N+1; ++j3) {
                                            if (!vec[j3-1]) {
                                                continue;
                                            }
                                            auto spin9 = TensorProduct(N+1);
                                            spin9.set(j3,array[i3]);
                                            auto prod8 = prod7*spin9;
                                            
                                            for (std::size_t i4 = 0; i4 < 3; ++i4) {
                                                auto spin10 = TensorProduct(N+1);
                                                spin10.set(0,array[i4]);
                                                auto prod9 = prod8*spin10;
                                                for (std::size_t j4 = 1; j4 < N+1; ++j4) {
                                                    if (!vec[j4-1]) {
                                                        continue;
                                                    }
                                                    auto spin11 = TensorProduct(N+1);
                                                    spin11.set(j4,array[i4]);
                                                    auto prod10 = prod9*spin11;
                                                    
                                                    sum += (prod10).trace()*vec[j0-1]*vec[j1-1]*vec[j2-1]*vec[j3-1]*vec[j4-1];
                                                    
                                                    
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    sum /= pow(2.0, N+1); // Divide by DOS
    // sum /= pow(2.0, 2); // Spin = sigma/2
    return (int)sum.real();
}

auto IzH0z6 (const std::vector<int> &vec) -> int {
    std::size_t N = vec.size(); // Number of bath spins
    
    std::complex<int> sum = 0;
    auto array = std::array<PauliMatrix, 3>{{PM::X, PM::Y, PM::Z}};
    for (std::size_t k0 = 0; k0 < N+1; ++k0) {
        auto spin0 = TensorProduct(N+1);
        spin0.set(k0,array[2]);
        
        for (std::size_t k1 = 0; k1 < N+1; ++k1) {
            auto spin1 = TensorProduct(N+1);
            spin1.set(k1,array[2]);
            auto prod0 = spin0*spin1;
            
            for (std::size_t i0 = 0; i0 < 3; ++i0) {
                auto spin2 = TensorProduct(N+1);
                spin2.set(0,array[i0]);
                auto prod1 = prod0*spin2;
                for (std::size_t j0 = 1; j0 < N+1; ++j0) {
                    if (!vec[j0-1]) {
                        continue;
                    }
                    auto spin3 = TensorProduct(N+1);
                    spin3.set(j0,array[i0]);
                    auto prod2 = prod1*spin3;
                    
                    for (std::size_t i1 = 0; i1 < 3; ++i1) {
                        auto spin4 = TensorProduct(N+1);
                        spin4.set(0,array[i1]);
                        auto prod3 = prod2*spin4;
                        for (std::size_t j1 = 1; j1 < N+1; ++j1) {
                            if (!vec[j1-1]) {
                                continue;
                            }
                            auto spin5 = TensorProduct(N+1);
                            spin5.set(j1,array[i1]);
                            auto prod4 = prod3*spin5;
                            
                            for (std::size_t i2 = 0; i2 < 3; ++i2) {
                                auto spin6 = TensorProduct(N+1);
                                spin6.set(0,array[i2]);
                                auto prod5 = prod4*spin6;
                                for (std::size_t j2 = 1; j2 < N+1; ++j2) {
                                    if (!vec[j2-1]) {
                                        continue;
                                    }
                                    auto spin7 = TensorProduct(N+1);
                                    spin7.set(j2,array[i2]);
                                    auto prod6 = prod5*spin7;
                                    
                                    for (std::size_t i3 = 0; i3 < 3; ++i3) {
                                        auto spin8 = TensorProduct(N+1);
                                        spin8.set(0,array[i3]);
                                        auto prod7 = prod6*spin8;
                                        for (std::size_t j3 = 1; j3 < N+1; ++j3) {
                                            if (!vec[j3-1]) {
                                                continue;
                                            }
                                            auto spin9 = TensorProduct(N+1);
                                            spin9.set(j3,array[i3]);
                                            auto prod8 = prod7*spin9;
                                            
                                            for (std::size_t i4 = 0; i4 < 3; ++i4) {
                                                auto spin10 = TensorProduct(N+1);
                                                spin10.set(0,array[i4]);
                                                auto prod9 = prod8*spin10;
                                                for (std::size_t j4 = 1; j4 < N+1; ++j4) {
                                                    if (!vec[j4-1]) {
                                                        continue;
                                                    }
                                                    auto spin11 = TensorProduct(N+1);
                                                    spin11.set(j4,array[i4]);
                                                    auto prod10 = prod9*spin11;
                                                    
                                                    for (std::size_t i5 = 0; i5 < 3; ++i5) {
                                                        auto spin12 = TensorProduct(N+1);
                                                        spin12.set(0,array[i5]);
                                                        auto prod11 = prod10*spin12;
                                                        for (std::size_t j5 = 1; j5 < N+1; ++j5) {
                                                            if (!vec[j5-1]) {
                                                                continue;
                                                            }
                                                            auto spin13 = TensorProduct(N+1);
                                                            spin13.set(j5,array[i5]);
                                                            auto prod12 = prod11*spin13;
                                                            
                                                            
                                                            sum += (prod12).trace()*vec[j0-1]*vec[j1-1]*vec[j2-1]*vec[j3-1]*vec[j4-1]*vec[j5-1];
                                                            
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    sum /= pow(2.0, N+1); // Divide by DOS
    // sum /= pow(2.0, 2); // Spin = sigma/2
    return (int)sum.real();
}

auto IzH0z7 (const std::vector<int> &vec) -> int {
    std::size_t N = vec.size(); // Number of bath spins
    
    std::complex<int> sum = 0;
    auto array = std::array<PauliMatrix, 3>{{PM::X, PM::Y, PM::Z}};
    for (std::size_t k0 = 0; k0 < N+1; ++k0) {
        auto spin0 = TensorProduct(N+1);
        spin0.set(k0,array[2]);
        
        for (std::size_t k1 = 0; k1 < N+1; ++k1) {
            auto spin1 = TensorProduct(N+1);
            spin1.set(k1,array[2]);
            auto prod0 = spin0*spin1;
            
            for (std::size_t i0 = 0; i0 < 3; ++i0) {
                auto spin2 = TensorProduct(N+1);
                spin2.set(0,array[i0]);
                auto prod1 = prod0*spin2;
                for (std::size_t j0 = 1; j0 < N+1; ++j0) {
                    if (!vec[j0-1]) {
                        continue;
                    }
                    auto spin3 = TensorProduct(N+1);
                    spin3.set(j0,array[i0]);
                    auto prod2 = prod1*spin3;
                    
                    for (std::size_t i1 = 0; i1 < 3; ++i1) {
                        auto spin4 = TensorProduct(N+1);
                        spin4.set(0,array[i1]);
                        auto prod3 = prod2*spin4;
                        for (std::size_t j1 = 1; j1 < N+1; ++j1) {
                            if (!vec[j1-1]) {
                                continue;
                            }
                            auto spin5 = TensorProduct(N+1);
                            spin5.set(j1,array[i1]);
                            auto prod4 = prod3*spin5;
                            
                            for (std::size_t i2 = 0; i2 < 3; ++i2) {
                                auto spin6 = TensorProduct(N+1);
                                spin6.set(0,array[i2]);
                                auto prod5 = prod4*spin6;
                                for (std::size_t j2 = 1; j2 < N+1; ++j2) {
                                    if (!vec[j2-1]) {
                                        continue;
                                    }
                                    auto spin7 = TensorProduct(N+1);
                                    spin7.set(j2,array[i2]);
                                    auto prod6 = prod5*spin7;
                                    
                                    for (std::size_t i3 = 0; i3 < 3; ++i3) {
                                        auto spin8 = TensorProduct(N+1);
                                        spin8.set(0,array[i3]);
                                        auto prod7 = prod6*spin8;
                                        for (std::size_t j3 = 1; j3 < N+1; ++j3) {
                                            if (!vec[j3-1]) {
                                                continue;
                                            }
                                            auto spin9 = TensorProduct(N+1);
                                            spin9.set(j3,array[i3]);
                                            auto prod8 = prod7*spin9;
                                            
                                            for (std::size_t i4 = 0; i4 < 3; ++i4) {
                                                auto spin10 = TensorProduct(N+1);
                                                spin10.set(0,array[i4]);
                                                auto prod9 = prod8*spin10;
                                                for (std::size_t j4 = 1; j4 < N+1; ++j4) {
                                                    if (!vec[j4-1]) {
                                                        continue;
                                                    }
                                                    auto spin11 = TensorProduct(N+1);
                                                    spin11.set(j4,array[i4]);
                                                    auto prod10 = prod9*spin11;
                                                    
                                                    for (std::size_t i5 = 0; i5 < 3; ++i5) {
                                                        auto spin12 = TensorProduct(N+1);
                                                        spin12.set(0,array[i5]);
                                                        auto prod11 = prod10*spin12;
                                                        for (std::size_t j5 = 1; j5 < N+1; ++j5) {
                                                            if (!vec[j5-1]) {
                                                                continue;
                                                            }
                                                            auto spin13 = TensorProduct(N+1);
                                                            spin13.set(j5,array[i5]);
                                                            auto prod12 = prod11*spin13;
                                                            
                                                            for (std::size_t i6 = 0; i6 < 3; ++i6) {
                                                                auto spin14 = TensorProduct(N+1);
                                                                spin14.set(0,array[i6]);
                                                                auto prod13 = prod12*spin14;
                                                                for (std::size_t j6 = 1; j6 < N+1; ++j6) {
                                                                    if (!vec[j6-1]) {
                                                                        continue;
                                                                    }
                                                                    auto spin15 = TensorProduct(N+1);
                                                                    spin15.set(j6,array[i6]);
                                                                    auto prod14 = prod13*spin15;
                                                                    
                                                                    sum += (prod14).trace()*vec[j0-1]*vec[j1-1]*vec[j2-1]*vec[j3-1]*vec[j4-1]*vec[j5-1]*vec[j6-1];
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    sum /= pow(2.0, N+1); // Divide by DOS
    // sum /= pow(2.0, 2); // Spin = sigma/2
    return (int)sum.real();
}
