using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class radioStop : MonoBehaviour
{
    
    
    public AudioSource Speaker;

    public void OnCollisionEnter(Collision collision)
    {
        Speaker.Play();
    }
    private void OnCollisionExit(Collision collision)
    {
        Speaker.Pause();
    }
}
