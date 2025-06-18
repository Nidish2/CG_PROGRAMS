# 🎨 Computer Graphics Programs – CG_PROGRAMS

Welcome to **CG_PROGRAMS**, a collection of core **Computer Graphics** programs implemented in C. This repository is designed for **engineering students**, especially from **BE/B.Tech CSE/IT** backgrounds, to practice and understand the fundamentals of graphics programming using **OpenGL** and **basic graphics logic** (like DDA, Bresenham's algorithm, etc.).

---

## 🧠 What's Inside?

This repo contains a wide range of **classic CG programs**, including both **2D and 3D graphics** concepts. Here's a categorized breakdown:

### ✅ Basic Line & Circle Drawing Algorithms:
| File Name | Description |
|----------|-------------|
| `1_DDA.c` | Digital Differential Analyzer (DDA) algorithm for line drawing |
| `2_Bresenham_F.c` | Bresenham’s Line Drawing algorithm |
| `26_Circle.c` | Midpoint Circle Drawing algorithm |

### 🎨 Polygon & Transformations:
| File Name | Description |
|----------|-------------|
| `6_Polygons.c` | Basic polygon drawing |
| `8_Polygon_Fillingg.c` | Polygon filling (e.g., boundary fill or flood fill) |
| `9_Polygon_Scaling.c` | Polygon scaling transformation |
| `19_Translation_scaling_F.c` | Translation and scaling (with buffer flush) |
| `25_Translation_scaling_no_bf.c` | Translation and scaling (no buffer flush) |

### 🌀 3D Objects & Advanced Shapes:
| File Name | Description |
|----------|-------------|
| `4_Tetrahedron.c` | 3D Tetrahedron |
| `16_coneNcylinder_F.c` | Cone and Cylinder rendering |
| `17_Wire_Sphere_F.c` | Wireframe Sphere |
| `20_Spinning_cube_F.c` | Rotating cube using animation |
| `21_Teapot.c` | Famous Utah Teapot (OpenGL predefined) |
| `22_Quadratic_surface.c` | Surface plotting using GLU Quadrics |
| `23_Polyhedron_perspective.c` | 3D Polyhedron with perspective |

### 🧭 Viewing & Clipping:
| File Name | Description |
|----------|-------------|
| `18_Perspective_viewing_F.c` | Perspective projection |
| `24_Cohen_Sutherland_Line_Clipping_F.c` | Line Clipping using Cohen-Sutherland algorithm |

### 📷 Real-World Simulation & Misc:
| File Name | Description |
|----------|-------------|
| `3_RealWorldPic_F.c` | Simulating a real-world picture (basic modeling) |
| `5_Types_Lines.c` | Demonstrating various line types (dashed, dotted) |
| `10_Rotate_Traingle_F.c` | Rotation of triangle |
| `7_Circle_F.c` | Filled circle using GL primitives |

---

## ⚙️ Requirements

- C/C++ Compiler (GCC/Clang)
- OpenGL libraries:
  - `GL`, `GLU`, `GLUT`
- Visual Studio / Code::Blocks / DevC++ / Linux Terminal
- Windows Users: Install `freeglut` or use `vcpkg` / `MSYS2` for OpenGL setup

---

## 🚀 How to Run

1. **Clone the Repository**
   ```bash
   git clone https://github.com/Nidish2/CG_PROGRAMS.git
   cd CG_PROGRAMS
