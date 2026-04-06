# 🚀 Install GCC on Windows (Using Chocolatey)

---

## 📌 Step 1: Install Chocolatey

Open **PowerShell as Administrator** and run:

```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; `
[System.Net.ServicePointManager]::SecurityProtocol = `
[System.Net.ServicePointManager]::SecurityProtocol -bor 3072; `
iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

---

## 📌 Step 2: Install GCC (MinGW)

```powershell
choco install mingw -y
```

---

## 📌 Step 3: Verify Installation

```bash
gcc --version
```

---

> ✅ If `gcc --version` prints a version number, GCC was installed successfully!
