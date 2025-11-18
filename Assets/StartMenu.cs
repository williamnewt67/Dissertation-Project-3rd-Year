using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class StartMenu : MonoBehaviour
{
    // Start is called before the first frame update
    public void Mainbutton()
    {
        SceneManager.LoadScene("RelaxingEnv"); // Loads Zen Garden scene when button is pressed in the main menu
    }



}
