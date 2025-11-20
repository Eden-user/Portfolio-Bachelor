# Magellan - Interactive Digital Flipbook

#README in progressn (ES6 modules details missing)... 

An offline-first interactive flipbook application designed to run on Android tablets without requiring internet connectivity. Magellan is a project made for [La Compagnie de la Lanterne Magique](https://www.compagnie-lanterne-magique.fr/)

## Overview

Magellan is a web-based application that uses HTML5, CSS3, and JavaScript to create a realistic page-flipping experience. The application is built to run entirely offline, with all resources cached locally on the tablet.

### Key Features

- **245-page flipbook** with realistic page-turning animations
- **Offline-first design** - runs without internet connectivity
- **Interactive navigation** with multiple content sections:
  - Home
  - Book chapters
  - Themes
  - Maps
  - Documents
  - Games
- **Modular ES6 architecture** for maintainable code
- **Responsive design** optimized for tablet displays
- **Touch-friendly interface** for intuitive interaction

## Technical Stack

- **jQuery** - DOM manipulation and event handling
- **turn.js** - Page-flipping functionality and animations
- **ES6 Modules** - Code organization and modularity
- **HTML5/CSS3** - Structure and styling

## Project Structure

```
magellan/
├── index.html              # Main application entry point
├── css/
│   └── styles.css         # Application styles
├── js/
│   ├── main.js            # Application initialization and routing
│   ├── Book.js            # Flipbook core functionality
│   ├── jquery/            # jQuery library
│   └── turn.js/           # turn.js library
│   └── [other modules]    # Additional feature modules, details to come
├── images/
    ├── 00.jpg             # Page images (00.jpg through 244.jpg)
    ├── 01.jpg
    └── ...

```

## Installation & Setup

### Running Locally on PC

1. **Install XAMPP**:
   - Download and install XAMPP from https://www.apachefriends.org/
   - Start the Apache server from the XAMPP control panel

2. **Set up the project**:
   - Copy the entire `magellan` folder to XAMPP's `htdocs` directory
   - Typical location: `C:\xampp\htdocs\magellan\`

3. **Access the application**:
   - Open your web browser
   - Navigate to `http://localhost/magellan/`
   - The application will load and be ready to use

4. **Test the application**:
   - Navigate through the flipbook and test all interactive features
   - Check all sections (chapters, themes, maps, documents, games)
   - No internet connection required - everything runs locally

### Deploying to Android Tablet

For tablet deployment, the application will use a **local web server app** running on the device:

1. **Transfer files**: Copy the entire `magellan` folder to your tablet's storage

2. **Install a local server app**: Use an app like "Simple HTTP Server" or similar from the Play Store

3. **Run the server**: Point the server app to the magellan folder and start it

4. **Access via localhost**: Open your browser and navigate to `localhost:[port]`. You may add a shortcut to the home page

This approach ensures the app works identically to the PC version while allowing data to be saved in cache for offline persistence.


### Code Architecture

The application uses a modular ES6 architecture:

**main.js** - Application initialization and routing
- Handles application startup
- Manages navigation between sections
- Coordinates module interactions

**Book.js** - Flipbook core functionality  
- Initializes turn.js
- Manages page flipping
- Handles book-specific interactions

### Navigation System

Navigation uses dropdown menus with unique IDs and data-toggle attributes:

```javascript
// Example navigation structure
<nav>
  <ul>
    <li data-toggle="home">Home</li>
    <li data-toggle="chapters">Chapters</li>
    <li data-toggle="themes">Themes</li>
    <!-- Additional sections -->
  </ul>
</nav>
```

The routing system handles content clearing and page transitions between sections.

## Contributing

This is a personal project, but suggestions and feedback are welcome.

## Acknowledgments

- **jQuery** - https://jquery.com/
- **turn.js** - http://www.turnjs.com/
- **image-map-resizer** - https://github.com/davidjbradshaw/image-map-resizer
- Built with care for offline accessibility

---

**Version**: 1.0  
**Last Updated**: November 2024  
**Platform**: Android tablets (offline)