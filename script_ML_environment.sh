#!/bin/bash
set -e

# === ACTUALIZACIÓN DEL SISTEMA ===
sudo pacman -Syu --noconfirm

# === HERRAMIENTAS BÁSICAS ===
sudo pacman -S --noconfirm base-devel git wget curl unzip zip htop neofetch tree

# === PYTHON Y PIP ===
sudo pacman -S --noconfirm python python-pip python-virtualenv

# === DESCARGA E INSTALACIÓN DE MAMBAFORGE (Conda + Mamba rápido) ===
cd /tmp
wget https://github.com/conda-forge/miniforge/releases/latest/download/Mambaforge-Linux-x86_64.sh -O Mambaforge.sh
bash Mambaforge.sh -b -p $HOME/mambaforge
rm Mambaforge.sh

# === CONFIGURAR PATH PARA CONDA/MAMBA ===
export PATH="$HOME/mambaforge/bin:$PATH"
echo 'export PATH="$HOME/mambaforge/bin:$PATH"' >> ~/.bashrc

# === ACTUALIZACIÓN DE CONDA/MAMBA ===
mamba update -n base -c defaults conda mamba -y

# === CREAR ENTORNO BASE ML ===
mamba create -n ml_base python=3.12 -y
echo "alias activate_ml='conda activate ml_base'" >> ~/.bashrc

# === INSTALAR JUPYTER Y UTILIDADES EN ml_base ===
conda activate ml_base
mamba install -y jupyterlab notebook ipython matplotlib seaborn numpy pandas scikit-learn plotly
mamba install -y tensorflow pytorch torchvision torchaudio cpuonly -c pytorch
mamba install -y notebook jupyter_contrib_nbextensions nodejs -c conda-forge
mamba install -y nb_conda_kernels -c conda-forge
conda deactivate

# === INSTALAR DOCKER ===
sudo pacman -S --noconfirm docker
sudo systemctl enable docker --now
sudo usermod -aG docker $USER

# === FIN DEL SCRIPT ===
echo "======================================"
echo "INSTALACIÓN COMPLETA!"
echo "Reinicia tu sesión o terminal para aplicar PATH y permisos de Docker"
echo "Usa 'activate_ml' para activar tu entorno base ML"
echo "Luego prueba: jupyter lab"
echo "======================================"
