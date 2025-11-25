# UD2 – Spring Boot: Guía profunda

---

## 1. De Spring Framework a Spring Boot

### 1.1 Spring Framework en contexto

- Spring Framework es un **framework empresarial para JVM** que da soporte a:
  - Aplicaciones web clásicas (MVC).
  - APIs REST.
  - Microservicios.
  - Integración con bases de datos (JDBC, JPA/Hibernate, NoSQL).
  - Seguridad (Spring Security, OAuth2, JWT, LDAP, etc.).
- La idea central es separar bien responsabilidades y delegar la infraestructura al framework:
  - Inversión de control (IoC).
  - Inyección de dependencias (DI).
  - Programación orientada a aspectos (AOP) para logging, transacciones, etc.

Problema: configurar Spring "a mano" (XML, Java config, servidores externos) era muy potente pero verboso para proyectos pequeños/medios.

### 1.2 Spring Boot: solución de productividad

Spring Boot nace para que arrancar un proyecto con Spring sea tan sencillo como:

1. Crear un proyecto con **Spring Initializr**.
2. Escribir tu lógica de negocio.
3. Ejecutar un único `.jar` con servidor embebido.

Ventajas clave:

- **Auto-configuración**: en función de las dependencias (`spring-boot-starter-web`, `spring-boot-starter-data-jpa`, etc.) Spring Boot configura automáticamente:
  - DispatcherServlet.
  - Tomcat embebido.
  - DataSource y EntityManager si hay JPA.
- **Convención sobre configuración**: hay valores por defecto razonables.
- **Starters**: agrupaciones de dependencias alineadas (web, test, security, etc.).
- **Empaquetado fácil**: `mvn spring-boot:run` o `java -jar miapp.jar`.

### 1.3 Spring Initializr en detalle

Cuando creas un proyecto en https://start.spring.io o desde IntelliJ:

- **Project**: Maven Project (lo habitual en DAM).
- **Language**: Java.
- **Spring Boot**: versión estable (2.x/3.x).
- **Project Metadata**:
  - `Group`: por ejemplo `com.example` o tu dominio `es.iesteis`.
  - `Artifact`: nombre del proyecto, p.e. `ud2-springboot-demo`.
  - `Name` y `Description`: informativo.
  - `Package name`: se suele derivar de group + artifact.
- **Packaging**: `jar` (por defecto). `war` solo si vas a desplegar en un servidor externo clásico.
- **Java**: versión de tu JDK (17 muy habitual).

Dependencias típicas en UD2:

- `Spring Web` (spring-boot-starter-web)
- `Thymeleaf`
- `Spring Data JPA`
- Driver de base de datos (H2, MariaDB, PostgreSQL, etc.)
- `Spring Boot DevTools` (opcional para recarga rápida en desarrollo)
- `Spring Boot Starter Test` (se añade casi siempre por defecto)

---

## 2. Estructura típica de un proyecto Spring Boot

La estructura base que genera Spring Initializr (simplificada):

```text
src
 └─ main
     ├─ java
     │   └─ com.example.demo
     │       └─ DemoApplication.java
     └─ resources
         ├─ application.properties
         ├─ static/
         └─ templates/
```

En un proyecto más realista de UD2, verás paquetes separados:

```text
src
 └─ main
     ├─ java
     │   └─ es.iesteis.demo
     │       ├─ DemoApplication.java        # Clase principal
     │       ├─ controller/                 # Controladores web
     │       ├─ service/                    # Lógica de negocio
     │       ├─ model/                      # Entidades de dominio (JPA)
     │       └─ repository/                 # Repositorios (Spring Data JPA)
     └─ resources
         ├─ application.properties          # Configuración
         ├─ templates/                      # Vistas Thymeleaf
         └─ static/                         # CSS, JS, imágenes
```

Idea mental:

- `controller` → traduce HTTP ⇆ Java (capa web).
- `service` → lógica de negocio (reglas, cálculos, validaciones).
- `model` → entidades de dominio, normalmente anotadas con JPA (`@Entity`).
- `repository` → interfaz con la base de datos.
- `templates` → HTML con Thymeleaf.
- `application.properties` → configuración externa.

---

## 3. Clase principal y arranque de la aplicación

### 3.1 Clase `@SpringBootApplication`

Código típico de la clase principal:

```java
package es.iesteis.demo;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class DemoApplication {

    public static void main(String[] args) {
        SpringApplication.run(DemoApplication.class, args);
    }
}
```

¿Qué hace `@SpringBootApplication`? Es una meta-anotación que agrupa:

- `@Configuration` → indica que esta clase puede definir beans de configuración.
- `@EnableAutoConfiguration` → activa la auto-configuración de Spring Boot.
- `@ComponentScan` → busca automáticamente componentes (`@Controller`, `@Service`, `@Repository`, `@Component`, etc.) dentro del paquete actual y subpaquetes.

### 3.2 Ciclo de arranque simplificado

1. Ejecutas `main` → `SpringApplication.run(...)`.
2. Spring crea el **ApplicationContext** (contenedor IoC).
3. Escanea el classpath en busca de beans anotados.
4. Aplica auto-configuración según dependencias y `application.properties`.
5. Arranca Tomcat embebido y queda escuchando en `server.port` (por defecto 8080).

---

## 4. Configuración con `application.properties`

Archivo: `src/main/resources/application.properties`.

### 4.1 Configuración básica del servidor

```properties
# Puerto de la aplicación
server.port=8080

# Prefijo para todas las rutas (opcional)
# server.servlet.context-path=/app
```

### 4.2 Configuración de base de datos (ejemplo H2 en memoria)

```properties
spring.datasource.url=jdbc:h2:mem:testdb
spring.datasource.driverClassName=org.h2.Driver
spring.datasource.username=sa
spring.datasource.password=

spring.jpa.hibernate.ddl-auto=update
spring.jpa.show-sql=true
spring.h2.console.enabled=true
spring.h2.console.path=/h2-console
```

Notas:

- `spring.jpa.hibernate.ddl-auto`:
  - `create-drop`: crea el esquema al arrancar y lo borra al parar.
  - `update`: actualiza el esquema sin borrar datos (útil en dev).
  - `validate`: comprueba que el esquema existe.
- `spring.jpa.show-sql=true` → muestra las sentencias SQL por consola.

### 4.3 Ejemplo con MariaDB / MySQL

```properties
spring.datasource.url=jdbc:mariadb://localhost:3306/ud2_demo
spring.datasource.username=ud2_user
spring.datasource.password=secreta
spring.datasource.driver-class-name=org.mariadb.jdbc.Driver

spring.jpa.hibernate.ddl-auto=update
spring.jpa.show-sql=true
spring.jpa.properties.hibernate.format_sql=true
```

---

## 5. Controladores Web (Controller Layer)

### 5.1 Controlador simple que devuelve texto

```java
package es.iesteis.demo.controller;

import es.iesteis.demo.service.SaludoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class SaludoController {

    private final SaludoService saludoService;

    @Autowired
    public SaludoController(SaludoService saludoService) {
        this.saludoService = saludoService;
    }

    @RequestMapping("/saludo/{nombre}")
    public @ResponseBody String saludo(@PathVariable("nombre") String nombre) {
        return saludoService.saluda(nombre);
    }
}
```

Claves:

- `@Controller` → indica que la clase pertenece a la capa web.
- `@RequestMapping("/saludo/{nombre}")` → mapea la URL a este método.
- `@PathVariable("nombre")` → extrae el segmento de la URL `{nombre}`.
- `@ResponseBody` → el valor devuelto se escribe directamente en el body (texto plano).

### 5.2 `@RestController` vs `@Controller`

- `@RestController` = `@Controller + @ResponseBody` por defecto.
- Se usa cuando la capa web devuelve **JSON** en lugar de vistas HTML.

```java
@RestController
@RequestMapping("/api/saludos")
public class SaludoRestController {

    private final SaludoService saludoService;

    public SaludoRestController(SaludoService saludoService) {
        this.saludoService = saludoService;
    }

    @GetMapping("/{nombre}")
    public SaludoDto saludo(@PathVariable String nombre) {
        return new SaludoDto(saludoService.saluda(nombre));
    }
}
```

---

## 6. Servicios, IoC e Inyección de Dependencias

### 6.1 Servicio de ejemplo

```java
package es.iesteis.demo.service;

import org.springframework.stereotype.Service;

@Service
public class SaludoService {

    public String saluda(String nombre) {
        if (nombre == null || nombre.isBlank()) {
            return "Hola mundo";
        }
        return "Hola " + nombre.trim();
    }
}
```

- `@Service` → marca la clase como **bean de servicio** (semánticamente forma parte de la lógica de negocio).
- Spring detecta automáticamente esta clase gracias a `@ComponentScan`.

### 6.2 IoC Container y Beans

- Un **bean** es un objeto gestionado por Spring.
- El **contenedor IoC** decide:
  - Cuándo instanciar el bean.
  - Su ciclo de vida.
  - Cómo inyectarlo en otros beans que lo necesitan.

En UD2 trabajarás casi siempre con el **scope Singleton**:

- Por defecto todos los beans (`@Controller`, `@Service`, `@Repository`) son `Singleton`.
- Implicación: **no guardes estado mutable compartido** en campos de estas clases.

### 6.3 Tipos de inyección de dependencias

1. **Constructor injection** (recomendada):

```java
@Controller
public class OtroController {

    private final SaludoService saludoService;

    public OtroController(SaludoService saludoService) {
        this.saludoService = saludoService;
    }
}
```

2. **Field injection** (funciona, pero es menos testeable):

```java
@Controller
public class OtroController {

    @Autowired
    private SaludoService saludoService;
}
```

3. **Setter injection** (útil si la dependencia es opcional):

```java
@Controller
public class OtroController {

    private SaludoService saludoService;

    @Autowired
    public void setSaludoService(SaludoService saludoService) {
        this.saludoService = saludoService;
    }
}
```

---

## 7. Thymeleaf y la capa de vista

### 7.1 Plantillas básicas

Carpeta: `src/main/resources/templates`.

Ejemplo de vista `saludo.html`:

```html
<!DOCTYPE html>
<html lang="es" xmlns:th="http://www.thymeleaf.org">
<head>
    <meta charset="UTF-8">
    <title>Saludo</title>
</head>
<body>
<h1 th:text="'Saludo: ' + ${mensaje}">Texto por defecto</h1>
</body>
</html>
```

Controller que renderiza la vista:

```java
package es.iesteis.demo.controller;

import es.iesteis.demo.service.SaludoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class SaludoPlantillaController {

    @Autowired
    private SaludoService saludoService;

    @RequestMapping("/saludoplantilla/{nombre}")
    public String saludo(@PathVariable String nombre, Model model) {
        model.addAttribute("mensaje", saludoService.saluda(nombre));
        return "saludo"; // busca templates/saludo.html
    }
}
```

### 7.2 Expresiones Thymeleaf útiles

- `${...}` → acceder a atributos del modelo (`model.addAttribute("mensaje", ...)`).
- `*{...}` → como `${...}` pero relativo al objeto asociado con `th:object`.
- `@{...}` → contruir URLs respetando el contexto de la aplicación.
- `th:text` → sustituye el contenido de una etiqueta por el valor de la expresión.
- `th:if` / `th:unless` → condicionales.
- `th:each` → bucles.

Ejemplo con lista:

```html
<ul>
    <li th:each="cliente : ${clientes}"
        th:text="${cliente.nombre}">Nombre cliente</li>
</ul>
```

---

## 8. Formularios, validación y flujo completo

### 8.1 Objeto de formulario con Bean Validation

```java
package es.iesteis.demo.model;

import jakarta.validation.constraints.Email;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Size;

public class UserData {

    @NotBlank(message = "El nombre no puede estar vacío")
    @Size(min = 3, max = 30, message = "El nombre debe tener entre 3 y 30 caracteres")
    private String nombre;

    @Email(message = "El email no tiene formato válido")
    private String email;

    // getters y setters

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
```

### 8.2 Formulario Thymeleaf

```html
<!DOCTYPE html>
<html lang="es" xmlns:th="http://www.thymeleaf.org">
<head>
    <meta charset="UTF-8">
    <title>Formulario de saludo</title>
</head>
<body>
<h1>Formulario de saludo</h1>

<form th:action="@{/saludoform}" th:object="${userData}" method="post">
    <table>
        <tr>
            <td>Nombre:</td>
            <td><input type="text" th:field="*{nombre}"/></td>
            <td th:if="${#fields.hasErrors('nombre')}"
                th:errors="*{nombre}"></td>
        </tr>
        <tr>
            <td>Email:</td>
            <td><input type="text" th:field="*{email}"/></td>
            <td th:if="${#fields.hasErrors('email')}"
                th:errors="*{email}"></td>
        </tr>
        <tr>
            <td colspan="3">
                <button type="submit">Enviar</button>
            </td>
        </tr>
    </table>
</form>

</body>
</html>
```

### 8.3 Controlador con validación

```java
package es.iesteis.demo.controller;

import es.iesteis.demo.model.UserData;
import es.iesteis.demo.service.SaludoService;
import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;

@Controller
public class SaludoFormController {

    @Autowired
    private SaludoService saludoService;

    @GetMapping("/saludoform")
    public String saludoForm(@ModelAttribute("userData") UserData userData) {
        // Solo muestra el formulario vacío
        return "formRegistro";
    }

    @PostMapping("/saludoform")
    public String procesarFormulario(@ModelAttribute("userData") @Valid UserData userData,
                                     BindingResult bindingResult,
                                     Model model) {

        if (bindingResult.hasErrors()) {
            // Volver al formulario mostrando los errores
            return "formRegistro";
        }

        // No hay errores → preparar respuesta
        String mensaje = saludoService.saluda(userData.getNombre());
        model.addAttribute("mensaje", mensaje);
        return "saludo";
    }
}
```

Flujo mental importante:

1. **GET `/saludoform`** → devuelve formulario vacío.
2. El usuario rellena datos y hace **submit**.
3. **POST `/saludoform`**:
   - Spring crea un `UserData` y lo rellena con los parámetros del form.
   - Aplica validaciones (`@Valid`).
   - Guarda resultados en `BindingResult`.
4. Si hay errores → se vuelve al formulario con mensajes.
5. Si todo está bien → se genera un saludo con el `Service` y se muestra la vista de éxito.

---

## 9. Testing en Spring Boot

### 9.1 Dependencias de test

En el `pom.xml` verás algo como:

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-test</artifactId>
    <scope>test</scope>
</dependency>
```

Incluye JUnit, AssertJ, Spring Test, Mockito, etc.

### 9.2 Test de servicios (unit tests)

```java
package es.iesteis.demo.service;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class SaludoServiceTest {

    private final SaludoService saludoService = new SaludoService();

    @Test
    void saludaConNombreValido() {
        String resultado = saludoService.saluda("Pepe");
        assertThat(resultado).isEqualTo("Hola Pepe");
    }

    @Test
    void saludaSinNombreDevuelveHolaMundo() {
        String resultado = saludoService.saluda("   ");
        assertThat(resultado).isEqualTo("Hola mundo");
    }
}
```

Características:

- No arranca Spring Boot, solo la clase a testear.
- Rápidos y aislados.

### 9.3 Test de la capa web con MockMvc (integration/web tests)

```java
package es.iesteis.demo.controller;

import es.iesteis.demo.service.SaludoService;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.web.servlet.MockMvc;

import static org.hamcrest.Matchers.containsString;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.content;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

@SpringBootTest
@AutoConfigureMockMvc
class SaludoControllerTest {

    @Autowired
    private MockMvc mockMvc;

    @Test
    void saludoDevuelveTextoCorrecto() throws Exception {
        mockMvc.perform(get("/saludo/Pepe"))
               .andExpect(status().isOk())
               .andExpect(content().string(containsString("Hola Pepe")));
    }
}
```

- `@SpringBootTest` → levanta el contexto completo de Spring Boot.
- `@AutoConfigureMockMvc` → configura `MockMvc` para simular peticiones HTTP sin servidor real.

También puede usarse `@WebMvcTest(SaludoController.class)` para hacer un **slice test** de la capa web únicamente, mockeando los servicios.

---

## 10. Spring Data JPA y Repositorios

### 10.1 Entidades JPA básicas

```java
package es.iesteis.demo.model;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;

@Entity
public class Customer {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;

    private String firstName;
    private String lastName;

    protected Customer() {
        // Requerido por JPA
    }

    public Customer(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public Long getId() {
        return id;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    @Override
    public String toString() {
        return "Customer{" +
                "id=" + id +
                ", firstName='" + firstName + ''' +
                ", lastName='" + lastName + ''' +
                '}';
    }
}
```

Claves:

- `@Entity` → marca la clase como entidad persistente.
- `@Id` → clave primaria.
- `@GeneratedValue` → estrategia de generación automática.
- Constructor vacío `protected` o `public` para JPA.

### 10.2 Repositorios con Spring Data

```java
package es.iesteis.demo.repository;

import es.iesteis.demo.model.Customer;
import org.springframework.data.repository.CrudRepository;

import java.util.List;

public interface CustomerRepository extends CrudRepository<Customer, Long> {

    // Finder methods derivados del nombre
    List<Customer> findByLastName(String lastName);

    List<Customer> findByFirstNameIgnoreCase(String firstName);
}
```

Spring implementa automáticamente estos métodos:

- `findByLastName("García")`
- `findByFirstNameIgnoreCase("ana")`

Uso en un servicio:

```java
package es.iesteis.demo.service;

import es.iesteis.demo.model.Customer;
import es.iesteis.demo.repository.CustomerRepository;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class CustomerService {

    private final CustomerRepository customerRepository;

    public CustomerService(CustomerRepository customerRepository) {
        this.customerRepository = customerRepository;
    }

    public Customer createCustomer(String firstName, String lastName) {
        Customer customer = new Customer(firstName, lastName);
        return customerRepository.save(customer);
    }

    public List<Customer> findByLastName(String lastName) {
        return customerRepository.findByLastName(lastName);
    }

    public Iterable<Customer> findAll() {
        return customerRepository.findAll();
    }
}
```

### 10.3 `CrudRepository` vs `JpaRepository`

- `CrudRepository<T, ID>` → operaciones básicas CRUD.
- `JpaRepository<T, ID>` → extiende `PagingAndSortingRepository` y añade:
  - Paginación.
  - Ordenación.
  - Métodos adicionales convenientes.

```java
import org.springframework.data.jpa.repository.JpaRepository;

public interface CustomerRepository extends JpaRepository<Customer, Long> {
    // mismos finder methods
}
```

---

## 11. Checklist mental para el examen de UD2

Si puedes explicar y escribir código de memoria (o casi) sobre:

1. Diferencia entre **Spring Framework** y **Spring Boot**.
2. Clase principal `@SpringBootApplication` y qué hace `SpringApplication.run(...)`.
3. Paquetes típicos: `controller`, `service`, `model`, `repository`, `templates`.
4. Uso de `application.properties` para:
   - Puerto.
   - Base de datos H2 / MariaDB.
   - Propiedades básicas de JPA.
5. Controladores web con:
   - `@Controller`, `@RestController`.
   - `@RequestMapping`, `@GetMapping`, `@PostMapping`.
   - `@PathVariable`, `@RequestParam`.
6. Servicios con `@Service` y DI (constructor injection).
7. Plantillas Thymeleaf con:
   - `th:text`, `th:each`, `th:if`.
   - Variables `${...}` y `th:object` + `*{...}`.
8. Formularios con validación:
   - `@Valid`, `BindingResult`.
   - Anotaciones `@NotBlank`, `@Size`, `@Email`.
9. Testing básico:
   - Test de servicios con JUnit + AssertJ.
   - Test web con `MockMvc` y `@SpringBootTest` o `@WebMvcTest`.
10. Entidades JPA + repositorios Spring Data:
    - `@Entity`, `@Id`, `@GeneratedValue`.
    - Interfaces que extienden `CrudRepository` / `JpaRepository`.
    - Métodos `findBy...` derivados del nombre.

Entonces tienes la UD2 de Spring Boot bien controlada para código y teoría.
