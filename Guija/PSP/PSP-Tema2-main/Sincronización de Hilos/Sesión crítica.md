Es una región de código diferenciable en la que se accede de forma **ordenada a variables / recursos de memoria compartidos**, la cual se ha de tener en cuenta que **nunca podrá ser asíncrona**.

Cuando un **proceso está ejecutando** **una sección crítica**, **ningún otro proceso lo puede hacer a la vez**.

---

Hay varias maneras de **permitir que varios procesos trabajen en una sesión crítica**:
### **Exclusión mutua**

 Permitir a solamente un proceso ejecutar la sesión crítica. **Garantizar que solo uno entra** .

### **Progreso**

Solamente deciden quién entra a la sección crítica los procesos que participen en ella. **Garantizar no esperar a los que no van a entrar**.


### **Espera limitada**

Hace que los procesos tengan limitado cuántas veces pueden entrar a la sección crítica si otro proceso ha solicitado entrar. **Garantiza que cada proceso que solicite entrar acabe entrando** sin quedar olvidado en la cola, para así no bloquear la ejecución.