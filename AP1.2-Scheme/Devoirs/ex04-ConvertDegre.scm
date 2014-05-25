;;; EXERCICE 4 : CONVERSION DEGRES FEHRENHEIT - CELSIUS

;;; FahrenheitToCelsius : Nombre -> Nombre
;;; Cette fonction sert a convertir une temperature en degre Fahrenheit au degre Celsius

(define (FahrenheitToCelsius tC)
  (/ (* 5 (- tC 32)) 9))

(verifier FahrenheitToCelsius          
          (FahrenheitToCelsius 0) => -160/9
          (FahrenheitToCelsius 100) => 340/9
          (FahrenheitToCelsius 50) => 10)
 
(FahrenheitToCelsius 100)


;;; CelsiusToFahrenheit : Nombre -> Nombre
;;; L'inverse version de la fonction precedente

(define (CelsiusToFahrenheit tC)
  (+ 32 (/ (* 9 tC) 5)))

(verifier CelsiusToFehrenheit
          (CelsiusToFahrenheit 0) => 32
          (CelsiusToFahrenheit 100) => 212
          (CelsiusToFahrenheit 50) => 122)

(CelsiusToFahrenheit (/ 340 9))
