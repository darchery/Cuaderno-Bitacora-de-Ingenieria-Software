        function crearParrafo() {
            const para = document.createElement("p");
            para.textContent = "You clicked the button!";
            document.body.appendChild(para);
        }

        const buttons = document.querySelectorAll("button");

        for (const button of buttons) {
            button.addEventListener("click", crearParrafo);
        }    
        // The following line is to ensure the script runs after the DOM is fully loaded
        document.addEventListener("DOMContentLoaded", () => {
            const buttons = document.querySelectorAll("button");
            for (const button of buttons) {
                button.addEventListener("click", crearParrafo);
            }
        });